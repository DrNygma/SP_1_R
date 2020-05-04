#include "Semaphore.h"

int main()
{
	setlocale(LC_ALL, "russian");
	int amount_of_handles; 
	int amount_of_threads;
	srand(time(NULL));
	printf("������� ���������� �������� ����������:");
	scanf("%i", &amount_of_handles);
	printf("������� ������������ ����� �������:");
	scanf("%i", &amount_of_threads);
	semaphore = CreateSemaphoreA(NULL, amount_of_handles, amount_of_handles, "MySemaphore");
	if (semaphore == NULL) {
		printf("��������� ������ �� ����� �������� ��������!");
		system("pause");
		return 1;
	}
	if (clear_file("threadsresult.txt"))
	{
		printf("��������� ������ �� ����� ������� �����!");
		system("pause");
		return 1;
	}
	WaitForMultipleObjects(amount_of_threads, launch_threads(amount_of_threads), TRUE, INFINITE);
	system("pause");
	return 0;
}