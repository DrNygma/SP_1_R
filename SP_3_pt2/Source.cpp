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
		printf("������� ����������:%s\n����:\n", buff);
		printf("1 - ����� ����������\n");
		printf("2 - ������ ������ ��������� ����������\n");
		printf("3 - ���������� ����\n");
		printf("4 - �������� ����������\n");
		printf("5 - �������� ��������� ���������� � �����\n");
		printf("6 - �������� ����� ��� ������ ����������\n");
		printf("7 - �����\n");
		printf("������� ����� ����:");
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
		default:printf("������ �������� ����� ���� ���������� ��� ���!\n");
		}
		system("pause");
		system("cls");
	}
}