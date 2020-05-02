#pragma once
#define ARRAY_MAX 10
CRITICAL_SECTION criticalSection;
HANDLE* threads;
int tlsIndex;

void print_array(int* arr)
{
	for (int i = 0; i < ARRAY_MAX; i++) {
		printf("%i ", arr[i]);
	}
}

int find_largest_divisor(int num)
{
	int j = num / 2;
	for (int i = j; i >= 2; i--)
	{
		if (num % i == 0)
			return i;
	}
}

int sum_elements(int* arr)
{
	int result = 0;

	for (int i = 0; i < ARRAY_MAX; i++)
	{
		result += arr[i];
	}

	return result;
}
void process_array(int* mainArr, int* resultArr)
{
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		resultArr[i] = find_largest_divisor(mainArr[i]);
	}
}

DWORD WINAPI thread_function(LPVOID param)
{
	EnterCriticalSection(&criticalSection);
	printf("Поток с номером %u;\n", GetCurrentThreadId());

	int* array = (int*)param;
	TlsSetValue(tlsIndex, (LPVOID)(new int[ARRAY_MAX]));
	int sum = 0;

	printf("Массив: ");
	print_array(array);

	process_array(array, (int*)TlsGetValue(tlsIndex));

	printf("\nОбработка массива в: ");
	print_array((int*)TlsGetValue(tlsIndex));

	sum = sum_elements((int*)TlsGetValue(tlsIndex));
	printf("\nСумма эл-тов: %d\n\n", sum);

	LeaveCriticalSection(&criticalSection);
	return 0;
}

void start(int count)
{
	InitializeCriticalSection(&criticalSection);
	int** arrays = new int* [count];
	tlsIndex = TlsAlloc();

	for (int i = 0; i < count; i++)
	{
		arrays[i] = new int[ARRAY_MAX];
		for (int j = 0; j < ARRAY_MAX; j++)
			arrays[i][j] = rand() % 90 + 10;

		threads[i] = CreateThread(NULL, 0, thread_function, arrays[i], NULL, NULL);
	}
}




