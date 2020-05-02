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
		printf("�������� ����� ����:\n");
		printf("1 - ���������;\n");
		printf("2 - ���������� ������;\n");
		printf("3 - �����.\n");
		scanf("%i", &choice);

		switch (choice)
		{
		case pack:
		{
			LPSTR unpacked = new CHAR[MAX_PATH];
			LPSTR result_file = new CHAR[MAX_PATH];

			printf("���� � ����� ��� ����������:");
			scanf("%s", unpacked);
			printf("���� � ���������� ������:");
			scanf("%s", result_file);
			if (pack_files(unpacked, result_file))
			{
				printf("��������� ���������!\n");
			}
			break;
		}
		case unpack:
		{
			LPSTR packed_file = new CHAR[MAX_PATH];
			LPSTR result_file = new CHAR[MAX_PATH];

			printf("������� ���� � ������:");
			scanf("%s", packed_file);
			printf("������� ���� ��� ���������� ������:");
			scanf("%s", result_file);
			if (unpack_files(packed_file, result_file))
			{
				printf("���������� ������ ���������.\n");
			}
			break;
		}
		case exit: return 0; break;
		default:printf("������ �������� ����� ����!\n");
		}
		system("pause");
		system("cls");
	}
}