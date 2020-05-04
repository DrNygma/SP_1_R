#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define ARRAY_MAX 100000

CRITICAL_SECTION section;
int* array;

int random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

void generate_array(int* array)
{
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		array[i] = random_int(0, 500);
	}
}

DWORD WINAPI thread_function_min(LPVOID use_critical_section)
{
	if ((bool)use_critical_section)
	{
		while (!TryEnterCriticalSection(&section))
		{
		}
	}

	int min = array[0];
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	printf("Минимальное значение массива: %i\n", min);

	if ((bool)use_critical_section)
	{
		LeaveCriticalSection(&section);
	}

	return 0;
}

DWORD WINAPI thread_function_avg(LPVOID use_critical_section)
{
	if ((bool)use_critical_section)
	{
		while (!TryEnterCriticalSection(&section))
		{
		}
	}

	float avg = 0;
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		avg += array[i];
	}
	printf("Среднее значение массива: %f\n", avg / ARRAY_MAX);

	if ((bool)use_critical_section)
	{
		LeaveCriticalSection(&section);
	}

	return 0;
}

DWORD WINAPI thread_function_max(LPVOID use_critical_section)
{
	if ((bool)use_critical_section)
	{
		while (!TryEnterCriticalSection(&section))
		{
		}
	}

	int max = array[0];
	for (int i = 0; i < ARRAY_MAX; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	printf("Максимальное значение массива:: %i\n", max);

	if ((bool)use_critical_section)
	{
		LeaveCriticalSection(&section);
	}

	return 0;
}
