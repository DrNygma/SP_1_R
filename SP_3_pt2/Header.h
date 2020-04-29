#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>;
#include <iostream>
#include <locale.h>
using namespace std;
// ����� ����������
void SetDirectory(TCHAR* buff);
// ����� ������ ��������� ����������
void PrintDirectory(TCHAR* buff);
// ����������� �����
void FileCopy(TCHAR* buff);
// �������� ����������
void MakeDirectory(TCHAR* buff);
// ��������� ���������� � �����
void DetailedInfoAboutFile(TCHAR* buff);
// �������� ����� ��� ������ ����������
void DeleteFileOrDirectory(TCHAR* buff);

void SetDirectory(TCHAR* buff) {
	for (;;) {
		printf("������� ������ ���� � ����������\n");
		printf("��������: C://folder\n>>");
		TCHAR path[MAX_PATH];
		getchar();
		fgets(path, MAX_PATH - 1, stdin);
		path[strlen(path) - 1] = '\0';
		if (!SetCurrentDirectory(path))
			printf("\n***������! �������� ���� � ����������. ***\n");
		else {
			GetCurrentDirectory(sizeof(path), path);
			printf("���� ������� ����������: %s\n", path);
			strcpy(buff, path);
			return;
		}
		system("pause");
	}
}
void PrintDirectory(TCHAR* buff) {
	printf("����� � ������� ����������: \n");
	WIN32_FIND_DATA FindFileData;
	TCHAR find[MAX_PATH];
	strcpy(find, buff);
	strcat(find, "\\*");
	HANDLE hf = FindFirstFile(find, &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do {
			SYSTEMTIME systime;
			FILETIME localfiletime;
			FileTimeToLocalFileTime(&FindFileData.ftCreationTime, &localfiletime);
			FileTimeToSystemTime(&localfiletime, &systime);
			LONGLONG size = (FindFileData.nFileSizeHigh * (MAXDWORD + 1)) + FindFileData.nFileSizeLow;
			printf("%-40s %20lu bytes ", FindFileData.cFileName, size);
			printf("%2u.%u.%u %u:%u\n", systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute);
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
void FileCopy(TCHAR* buff) {
	for (;;) {
		printf("������� ��� ����� � ������� ���������� �������� lab1.txt\n>>");
		TCHAR find[MAX_PATH], s[MAX_PATH], newDirectory[MAX_PATH];
		strcpy(find, buff);
		getchar();
		fgets(s, MAX_PATH - 1, stdin);
		s[strlen(s) - 1] = '\0';
		strcat(find, "\\");
		strcat(find, s);
		printf("\n������� ���� ���� ������� ���������� ���� ��������(D://...)\n>>");
		fgets(newDirectory, MAX_PATH - 1, stdin);
		newDirectory[strlen(newDirectory) - 1] = '\0';
		strcat(newDirectory, "\\");
		strcat(newDirectory, s);
		if (CopyFile(find, newDirectory, false)) return;
		else cout << "***������! ������������ ���� ��� ��� ����� ***\n";
	}
}
void MakeDirectory(TCHAR* buff) {
	TCHAR newDir[MAX_PATH], way[MAX_PATH];
	printf("\n������� �������� ����� ����������\n>>");
	getchar();
	fgets(newDir, MAX_PATH - 1, stdin);
	newDir[strlen(newDir) - 1] = '\0';
	strcpy(way, buff);
	strcat(way, "\\");
	strcat(way, newDir);
	if (CreateDirectory(way, NULL))
		printf("���������� ������� �������\n");
	else
		printf("***������! �� ������� ������� ���������� ***\n");
}
void DetailedInfoAboutFile(TCHAR* buff) {
	TCHAR file[MAX_PATH], way[MAX_PATH];
	printf("������� ��� �����:\n>>");
	getchar();
	fgets(file, MAX_PATH - 1, stdin);
	file[strlen(file) - 1] = '\0';
	strcpy(way, buff);
	strcat(way, "\\");
	strcat(way, file);
	HANDLE hFile1 = CreateFile(way, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	BY_HANDLE_FILE_INFORMATION information;
	BOOL f = GetFileInformationByHandle(hFile1, &information);
	CloseHandle(hFile1);
	if (!f) {
		printf("*** ������ ������������ ��� ����� ***\n");
	}
	else {
		printf("���� ");
		if ((information.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) != 0)
			printf("������� ");
		if ((information.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) != 0)
			printf("��������� ");
		if ((information.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) != 0)
			printf("����� ");
		if ((information.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED) != 0)
			printf("������ ");
		if ((information.dwFileAttributes & FILE_ATTRIBUTE_NORMAL) != 0)
			printf("���������� ");
		cout << ".\n";
		SYSTEMTIME systime;
		FILETIME localfiletime;
		FileTimeToLocalFileTime(&information.ftCreationTime, &localfiletime);
		FileTimeToSystemTime(&localfiletime, &systime);
		printf("����� �������� - %2u.%u.%u %u:%u\n", systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute);
		FileTimeToLocalFileTime(&information.ftLastWriteTime, &localfiletime);
		FileTimeToSystemTime(&localfiletime, &systime);
		printf("����� ��������� - %2u.%u.%u %u:%u\n", systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute);
	}
}
void DeleteFileOrDirectory(TCHAR* buff) {
	TCHAR file[MAX_PATH], way[MAX_PATH];
	printf("������� ��� ����� ��� ���������� ������� �� ������ �������!\n>>");
	getchar();
	fgets(file, MAX_PATH - 1, stdin);
	file[strlen(file) - 1] = '\0';
	strcpy(way, buff);
	strcat(way, "\\");
	strcat(way, file);
	BOOL g = DeleteFile(way), k;
	if (!g) {
		k = RemoveDirectory(way);
	}
	if (!g && !k) {
		DWORD lastErrorCode = GetLastError();
		void* cstr; //� ��� ���������� ����� �������� ���������
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&cstr,
			0,
			NULL
		);
		// �������������� ��������� � ����������� ���
		PTCHAR res((char*)cstr);
		printf("%s", res);
	}
}