#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <Windows.h>
int main(void)
{
	setlocale(LC_ALL, "rus");
	printf("Тип данных Bool:\n");
	printf("Размер: %i байт;\n",sizeof(BOOL));
	printf("Значения: true/false;\n",CHAR_MAX,CHAR_MAX);
	printf("\n");
	printf("Тип данных Byte:\n");
	printf("Размер: %i байт;\n", sizeof(BYTE));
	printf("MAX(10): %d, (16): %#x;\n", UCHAR_MAX, UCHAR_MAX);
	printf("MIN(10): 0, (16): 0x00000000;\n");
	printf("\n");
	printf("Тип данных Int:\n");
	printf("Размер: %i байт;\n", sizeof(INT));
	printf("MAX(10): %d, (16): %#x;\n", INT_MAX, INT_MAX);
	printf("MIN(10): %d, (16): %#x;\n", INT_MIN, INT_MIN);
	printf("\n");
	printf("Тип данных Dword:\n");
	printf("Размер: %i байт;\n", sizeof(DWORD));
	printf("MAX(10): 4294967293‬, (16): 0xfffffffd‬;\n");
	printf("MIN(10): 0, (16): 0x00000000;\n");
	printf("\n");
	printf("Тип данных Long:\n");
	printf("Размер: %i байт;\n", sizeof(LONG));
	printf("MAX(10): %ld, (16): %#x;\n", LONG_MAX, LONG_MAX);
	printf("MIN(10): %ld, (16): %#x;\n", LONG_MIN, LONG_MIN);
	printf("\n");
	printf("Тип данных Null- нулевой указатель:\n");
	printf("Размер: %i байт;\n", sizeof(NULL));
	printf("\n");
	printf("Тип данных UInt:\n");
	printf("Размер: %i байт;\n", sizeof(UINT));
	printf("MAX(10): 4294967293‬, (16): 0xfffffffd‬;\n");
	printf("MIN(10): 0, (16): 0x00000000;\n");
	printf("\n");
	return 0;
}