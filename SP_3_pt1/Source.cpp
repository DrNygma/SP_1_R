#define _CRT_SECURE_NO_WARNINGS
#include "locale.h"
#include "windows.h"
#include "stdio.h"
#include "header.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		printf("1 - ����������� ��� ������\n");
		printf("2 - �������� ������\n");
		printf("3 - �������� ������\n");
		printf("4 - ������� ������\n");
		printf(">>");
		int i;
		scanf_s("%i", &i);
		switch (i)
		{
		case 1: print_all(); break;
		case 2: add_record(); break;
		case 3: edit_record(); break;
		case 4: remove_record(); break;
		default: printf("������ �������� ��� :(\n");
		}
		system("pause");
		system("cls");
	}
}