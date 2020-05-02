#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <time.h>
#include "Potoki.h"
int main()
{
	int count;

	printf("¬ведите кол-во потоков:\n");
	scanf("%i", &count);

	threads = new HANDLE[count];
	srand(time(0));
	InitializeCriticalSection(&criticalSection);
	start(count);
	WaitForMultipleObjects(count, threads, TRUE, INFINITE);
	DeleteCriticalSection(&criticalSection);
	return 0;
}