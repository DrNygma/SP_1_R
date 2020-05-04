#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE mutex = CreateMutexA(NULL, FALSE, "Мьютекс");

	if (WaitForSingleObject(mutex, 0) == WAIT_OBJECT_0)
	{
		printf("Программа запущена! Нажмите любую кнопку чтобы её закрыть.");
		getchar();
		ReleaseMutex(mutex);
	}
	else
	{
		printf("Программа уже запущена! Невозможно создать новый экземпляр!");
		getchar();
	}

	CloseHandle(mutex);
	return 0;
}