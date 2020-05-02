#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "7z.h"
#define pack 1
#define unpack 2
#define exit 3

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	for (;;)
	{
		system("cls");;
		printf("Выберите пункт меню:\n");
		printf("1 - Архивация;\n");
		printf("2 - Распаковка архива;\n");
		printf("3 - Выход.\n");
		scanf("%i", &choice);

		switch (choice)
		{
		case pack:
		{
			LPSTR unpacked = new CHAR[MAX_PATH];
			LPSTR result_file = new CHAR[MAX_PATH];

			printf("Путь к файлу или директории:");
			scanf("%s", unpacked);
			printf("Путь к созданному архиву:");
			scanf("%s", result_file);
			if (pack_files(unpacked, result_file))
			{
				printf("Архивация завершена!\n");
			}
			break;
		}
		case unpack:
		{
			LPSTR packed_file = new CHAR[MAX_PATH];
			LPSTR result_file = new CHAR[MAX_PATH];

			printf("Введите путь к архиву:");
			scanf("%s", packed_file);
			printf("Введите путь для распаковки архива:");
			scanf("%s", result_file);
			if (unpack_files(packed_file, result_file))
			{
				printf("Распаковка архива завершена.\n");
			}
			break;
		}
		case exit: return 0; break;
		default:printf("Выбран неверный пункт меню!\n");
		}
		system("pause");
		system("cls");
	}
}