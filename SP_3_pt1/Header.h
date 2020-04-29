#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
LPCSTR file_name = "Notes.txt";

struct Record
{
	UINT number;
	FILETIME time;
	TCHAR data[81];
	UINT changes;
};

struct Header
{
	UINT records;
	UINT file_size;
};

Header get_header();
vector<Record> get_records();
void print_all();
void add_record();
void edit_record();
void remove_record();

Header get_header()
{
	HANDLE hFile = CreateFileA(file_name, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_BEGIN);
	Header header;
	DWORD readed;
	ReadFile(hFile, &header, sizeof(Header), &readed, NULL);
	if (readed == 0)
	{
		header.records = 0;
		header.file_size = 0;
	}
	CloseHandle(hFile);
	return header;
}

vector<Record> get_records()
{
	HANDLE hFile = CreateFileA(file_name, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(hFile, sizeof(Header), NULL, FILE_BEGIN);
	vector<Record> records(0);

	Record record;
	DWORD readed = 0;
	while (true)
	{
		ReadFile(hFile, &record, sizeof(Record), &readed, NULL);

		if (readed == 0)
			break;

		records.push_back(record);
	}
	CloseHandle(hFile);

	return records;
}

void print_all()
{
	SYSTEMTIME time;
	vector <Record> records = get_records();
	Header header = get_header();
	printf("������ �����: %uB\n���������� �������: %u\n", header.file_size, header.records);
	printf("**********************************\n");
	for (int i = 0; i < records.size(); i++)
	{
		FileTimeToSystemTime(&records[i].time, &time);
		printf("������ �%i \n", records[i].number);
		printf("�������: %02d-%02d-%d %02d:%02d:%02d \n", time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute, time.wSecond);
		printf("�������� %u ��� \n", records[i].changes);
		printf("�����: %s\n", records[i].data);
		printf("**********************************\n");
	}
}

void add_record()
{
	Header header = get_header();
	vector<Record> records = get_records();
	SYSTEMTIME sTime;
	GetLocalTime(&sTime);
	FILETIME fTime;
	Record record;
	SystemTimeToFileTime(&sTime, &fTime);
	printf("������� �����(80 ��������)\n");
	printf(">>");
	getchar();
	fgets(record.data, 80, stdin);
	record.number = records.size();
	record.time = fTime;
	record.changes = 0;
	header.records++;
	records.push_back(record);
	header.file_size = sizeof(header) + sizeof(Record) * records.size();
	HANDLE hFile = CreateFile(file_name, GENERIC_WRITE, NULL, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_BEGIN);
	WriteFile(hFile, &header, sizeof(Header), NULL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_END);
	for (int i = 0; i < records.size(); i++)
	{
		WriteFile(hFile, &records[i], sizeof(Record), NULL, NULL);
	}
	CloseHandle(hFile);
}

void edit_record()
{
	SYSTEMTIME sTime;
	Header header = get_header();
	vector <Record> records = get_records();
	UINT index;
	printf("������� ����� ������\n");
	printf(">>");
	scanf("%i", &index);
	if (index >= records.size())
	{
		printf("����� ������ ���!\n");
		return;
	}
	printf("����� ������ ������: ");
	printf("%s\n", records[index].data);
	printf("������� ����� �����\n");
	printf(">>");
	TCHAR new_data[81];
	getchar();
	fgets(new_data, 80, stdin);
	if (strcmp(records[index].data, new_data) != 0)
	{
		strcpy(records[index].data, new_data);
		records[index].changes++;
	}
	HANDLE hFile = CreateFileA(file_name, GENERIC_WRITE, NULL, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_BEGIN);
	WriteFile(hFile, &header, sizeof(Header), NULL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_END);
	for (int i = 0; i < records.size(); i++)
	{
		WriteFile(hFile, &records[i], sizeof(Record), NULL, NULL);
	}
	CloseHandle(hFile);
}

void remove_record()
{
	Header header = get_header();
	vector <Record> records = get_records();
	UINT index;
	printf("������� ����� ������\n");
	printf(">>");
	scanf("%i", &index);
	if (index >= records.size())
	{
		printf("����� ������ ���!\n");
		return;
	}
	records.erase(records.begin() + index);
	header.records--;
	for (int i = 0; i < records.size(); i++)
	{
		records[i].number = i;
	}
	header.file_size = sizeof(header) + sizeof(Record) * records.size();
	HANDLE hFile = CreateFileA(file_name, GENERIC_WRITE, NULL, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_BEGIN);
	WriteFile(hFile, &header, sizeof(Header), NULL, NULL);
	SetFilePointer(hFile, NULL, NULL, FILE_END);
	for (int i = 0; i < records.size(); i++)
	{
		WriteFile(hFile, &records[i], sizeof(Record), NULL, NULL);
	}
	CloseHandle(hFile);
}