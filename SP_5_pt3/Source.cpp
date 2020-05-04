#include "Self_exec.h"
#include "locale.h"
int main()
{
	setlocale(LC_ALL, "rus");   
	HANDLE* threads;
	clock_t start;
	float elapsed_time;

	srand(time(NULL));
	InitializeCriticalSection(&section);

	array = new int[ARRAY_MAX];
	generate_array(array);

	start = clock();
	threads = new HANDLE[3];
	threads[0] = CreateThread(NULL, 0, thread_function_min, (LPVOID)TRUE, NULL, NULL);
	threads[1] = CreateThread(NULL, 0, thread_function_avg, (LPVOID)TRUE, NULL, NULL);
	threads[2] = CreateThread(NULL, 0, thread_function_max, (LPVOID)TRUE, NULL, NULL);
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	for (int i = 0; i < 3; i++)
		CloseHandle(threads[i]);

	elapsed_time = ((float)(clock() - start)) / CLK_TCK;
	printf("Время работы программы с взаимоисключением: %f секунд\n\n", elapsed_time);

	start = clock();
	threads = new HANDLE[3];
	threads[0] = CreateThread(NULL, 0, thread_function_min, (LPVOID)FALSE, NULL, NULL);
	threads[1] = CreateThread(NULL, 0, thread_function_avg, (LPVOID)FALSE, NULL, NULL);
	threads[2] = CreateThread(NULL, 0, thread_function_max, (LPVOID)FALSE, NULL, NULL);
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	for (int i = 0; i < 3; i++)
		CloseHandle(threads[i]);

	elapsed_time = ((float)(clock() - start)) / CLK_TCK;
	printf("Время работы программы без взаимоисключения: %f секунд\n\n", elapsed_time);

	DeleteCriticalSection(&section);
}