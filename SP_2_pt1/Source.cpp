#include "locale.h"
#include "windows.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc == 2)
    {
        if (strcmp(argv[1], "-s") == 0)
        {
            MEMORYSTATUSEX ms;
            SYSTEM_INFO proc;
            GlobalMemoryStatusEx(&ms);
            printf_s("����� ���������� � ������:");
            printf_s("�������� ������: %d ����;\n", ms.ullAvailPhys);
            printf_s("����� ���� ������: %d ����;\n", ms.ullTotalPhys);
            GetSystemInfo(&proc);
            printf_s("����� ���������� � ����������:");
            printf_s("Number of processors: %u\n", proc.dwNumberOfProcessors);
            printf_s("Processor architecture: %u\n", proc.wProcessorArchitecture);
            printf_s("Processor level: %u\n", proc.wProcessorLevel);
            printf_s("Processor revision: %u\n", proc.wProcessorRevision);
            printf_s("Active processor mask: %u\n", proc.dwActiveProcessorMask);
            printf_s("Page size: %u\n", proc.dwPageSize);
            printf_s("Minimum application address: %lx\n", proc.lpMinimumApplicationAddress);
            printf_s("Maximum application address: %lx\n", proc.lpMaximumApplicationAddress);
        }
        else if (strcmp(argv[1], "-e") == 0)
        {
            MEMORYSTATUS ms;
            GlobalMemoryStatus(&ms);

            HLOCAL memory = LocalAlloc(LPTR, ms.dwLength * (-1));
            if (memory == NULL) {
                LPVOID message;
                DWORD code = GetLastError();
                FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
                    code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&message, 0, NULL);
                wprintf(L"��� ��������������� ������: 0x%x\n", code);
                wprintf(L"��������� �� ������: %s\n", (char*)message);
            }
            else {
                LocalFree(memory);
            }
            //���������
        }
        else
        {
            printf_s("����� �������� ��������!");
        }
    }
    else
    {
        printf_s("������� �������� ���������� ���������� ��������� ������!");
    }

    return 0;
}