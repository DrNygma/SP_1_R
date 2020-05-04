#include <stdio.h>
#include <Windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE mutex = CreateMutexA(NULL, FALSE, "�������");

	if (WaitForSingleObject(mutex, 0) == WAIT_OBJECT_0)
	{
		printf("��������� ��������! ������� ����� ������ ����� � �������.");
		getchar();
		ReleaseMutex(mutex);
	}
	else
	{
		printf("��������� ��� ��������! ���������� ������� ����� ���������!");
		getchar();
	}

	CloseHandle(mutex);
	return 0;
}