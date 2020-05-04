#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

HANDLE semaphore;

int random_integer(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

bool clear_file(LPCSTR filename)
{
	bool operation_failed = false;
	HANDLE file = CreateFileA(filename, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE)
	{
		operation_failed = true;
	}
	CloseHandle(file);
	return  operation_failed;
}
DWORD WINAPI thread_function(LPVOID param)
{
	int* params = (int*)param;
	clock_t start = clock();
	int thread_number = params[0];
	LPSTR str = new CHAR[128];

	DWORD result = WaitForSingleObject(semaphore, 500);
	while (result != WAIT_OBJECT_0)
	{
		result = WaitForSingleObject(semaphore, 1000);
		printf("Поток №%i ожидает указатель\n", thread_number);
	}
	printf("Поток №%i получил указатель. Переход в спящий режим.\n", thread_number);
	Sleep(params[1] * 1000);
	HANDLE file = CreateFileA("threadsresult.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE)
	{
		ReleaseSemaphore(semaphore, 1, NULL);
		return 0;
	}
	SetFilePointer(file, 0, NULL, FILE_END);
	clock_t finish = clock();
	float time_elapsed = (finish - start) / CLK_TCK;
	sprintf(str, "Поток №%i завершил свою работу спустя %f секунд\n\0", thread_number, time_elapsed);
	WriteFile(file, str, strlen(str), NULL, NULL);
	CloseHandle(file);

	printf("Поток №%i освободил указатель.\n", thread_number);
	ReleaseSemaphore(semaphore, 1, NULL);
	return 0;
}
HANDLE* launch_threads(int count)
{
	HANDLE* threads = new HANDLE[count];
	for (int i = 0; i < count; i++)
	{
		int* params = new int[2];
		params[0] = i;
		params[1] = random_integer(1, 3); 
		threads[i] = CreateThread(
			NULL, 0,thread_function,(LPVOID)params,NULL,NULL);
	}
	return threads;
}