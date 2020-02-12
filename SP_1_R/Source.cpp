#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <Windows.h>
int main(void)
{
	setlocale(LC_ALL, "rus");
	printf("Тип данных Bool:\n");
	printf("Размер: %i байт;\n",sizeof(BOOL));
	printf("Значения: true/false;\n");
	printf("\n");
	printf("Тип данных Char:\n");
	printf("Размер: %i байт;\n", sizeof(char));
	printf("MAX(10): %d;\n", CHAR_MAX);
	printf("MIN(10): %d;\n", CHAR_MIN);
	printf("\n");
	printf("Тип данных Signed char:\n");
	printf("Размер: %i байт;\n", sizeof(signed char));
	printf("MAX(10): %d;\n", SCHAR_MAX);
	printf("MIN(10): %d;\n", SCHAR_MIN);
	printf("\n");
	printf("Тип данных Unsigned char:\n");
	printf("Размер: %i байт;\n", sizeof(unsigned char));
	printf("MAX(10): %d;\n", UCHAR_MAX);
	printf("MIN(10): 0;\n");
	printf("\n");
	printf("Тип данных Int:\n");
	printf("Размер: %i байт;\n", sizeof(int));
	printf("MAX(10): %d;\n", INT_MAX);
	printf("MIN(10): %d;\n", INT_MIN);
	printf("\n");
	printf("Тип данных Unsigned int:\n");
	printf("Размер: %u байт;\n", sizeof(unsigned int));
	printf("MAX(10): %u;\n", UINT_MAX);
	printf("MIN(10): 0;\n");
	printf("\n");
	printf("Тип данных Long:\n");
	printf("Размер: %ld байт;\n", sizeof(long));
	printf("MAX(10): %ld;\n", LONG_MAX);
	printf("MIN(10): %ld;\n", LONG_MIN);
	printf("\n");
	printf("Тип данных Unsigned long:\n");
	printf("Размер: %lu байт;\n", sizeof(unsigned long));
	printf("MAX(10): %lu;\n", ULONG_MAX);
	printf("MIN(10): 0\n");
	printf("\n");
	printf("Тип данных Double:\n");
	printf("Размер: %i байт;\n", sizeof(double));
	printf("MAX(10): %e;\n", DBL_MAX);
	printf("MIN(10): %e;\n", DBL_MIN);
	printf("\n");
	printf("Тип данных Long double:\n");
	printf("Размер: %i байт;\n", sizeof (long double));
	printf("MAX(10): %e;\n", LDBL_MAX);
	printf("MIN(10): %e;\n", LDBL_MIN);
	printf("\n");
	printf("Тип данных Float:\n");
	printf("Размер: %i байт;\n", sizeof(float));
	printf("MAX(10): %e;\n", FLT_MAX);
	printf("MIN(10): %e;\n", FLT_MIN);
	printf("\n");
	printf("Тип данных Short:\n");
	printf("Размер: %i байт;\n", sizeof(short));
	printf("MAX(10): %i;\n", SHRT_MAX);
	printf("MIN(10): %i;\n", SHRT_MIN);
	printf("\n");
	printf("Тип данных Unsigned short:\n");
	printf("Размер: %i байт;\n", sizeof(unsigned short));
	printf("MAX(10): %i;\n", USHRT_MAX);
	printf("MIN(10): 0;\n");
	printf("\n");
	printf("Тип данных Null- нулевой указатель:\n");
	printf("Размер: %i байт;\n", sizeof(NULL));
	printf("\n");
	return 0;
}