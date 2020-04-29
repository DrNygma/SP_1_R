#define _CRT_SECURE_NO_WARNINGS
#include "locale.h"
#include "windows.h"
#include "stdio.h"
#include "header.h"
int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	for (;;) {
		TCHAR buff[MAX_PATH];
		GetCurrentDirectory(sizeof(buff), buff);
		system("cls");
		printf("Текущая директория:%s\nМеню:\n", buff);
		printf("1 - Выбор директории\n");
		printf("2 - Печать файлов выбранной директории\n");
		printf("3 - Копировать файл\n");
		printf("4 - Создание директории\n");
		printf("5 - Получить подробную информацию о файле\n");
		printf("6 - Удаление файла или пустой директории\n");
		printf("7 - Выход\n");
		printf("Введите пункт меню:");
		scanf("%i", &choice);
		system("cls");
		switch (choice) {
		case 1: SetDirectory(buff); break;
		case 2: PrintDirectory(buff); break;
		case 3: FileCopy(buff); break;
		case 4:	MakeDirectory(buff); break;
		case 5: DetailedInfoAboutFile(buff); break;
		case 6: DeleteFileOrDirectory(buff); break;
		case 7: return 0; break;
		default:printf("Выбран неверный пункт меню попробуйте еще раз!\n");
		}
		system("pause");
		system("cls");
	}
}