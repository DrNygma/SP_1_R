#pragma once
void print_error()
{
	printf("\n***Ошибка!***\nТекст ошибки:");
	void* cstr; 
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&cstr,
		0,
		NULL
	);
	PTCHAR res((char*)cstr);
	printf("%s", res);
}
bool launch_process(LPSTR command_line) {
	HANDLE read_pipe;
	HANDLE write_pipe;
	SECURITY_ATTRIBUTES security_attributes;
	security_attributes.nLength = sizeof(SECURITY_ATTRIBUTES);
	security_attributes.bInheritHandle = TRUE;
	security_attributes.lpSecurityDescriptor = NULL;

	CreatePipe(&read_pipe, &write_pipe, &security_attributes, 0);
	if (read_pipe == INVALID_HANDLE_VALUE || write_pipe == INVALID_HANDLE_VALUE)
	{
		print_error();
		return false;
	}

	if (!SetHandleInformation(read_pipe, HANDLE_FLAG_INHERIT, 0))
	{
		print_error();
		return false;
	}

	STARTUPINFOA startup_info;
	ZeroMemory(&startup_info, sizeof(STARTUPINFOA));
	startup_info.cb = sizeof(startup_info);
	startup_info.hStdError = write_pipe;
	startup_info.dwFlags |= STARTF_USESTDHANDLES;

	PROCESS_INFORMATION process_information;
	ZeroMemory(&process_information, sizeof(process_information));

	if (!CreateProcessA(NULL, command_line, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startup_info, &process_information)) {
		print_error(); 
		return false;
	}
	WaitForSingleObject(process_information.hProcess, INFINITE);
	DWORD readed = 0;
	LPSTR result = new CHAR[1024];
	ZeroMemory(result, 1024);
	OVERLAPPED overlapped;
	while (ReadFile(read_pipe, result, 1024, &readed, &overlapped))
	{
		printf("%s", result);
	}
	CloseHandle(read_pipe);
	CloseHandle(write_pipe);
	CloseHandle(process_information.hProcess);
	CloseHandle(process_information.hThread);
	return true;
}
bool unpack_files(LPSTR packed_file, LPSTR result_file)
{
	LPSTR command_line = new CHAR[MAX_PATH];
	ZeroMemory(command_line, MAX_PATH);
	strncpy(command_line, "C:\\Program Files (x86)\\7-Zip\\7z.exe e", MAX_PATH - strlen(command_line));
	strncat(command_line, packed_file, MAX_PATH - strlen(command_line));
	strncat(command_line, " -o", MAX_PATH - strlen(command_line));
	strncat(command_line, result_file, MAX_PATH - strlen(command_line));
	strncat(command_line, " -y", MAX_PATH - strlen(command_line));
	return launch_process(command_line);
}
bool pack_files(LPSTR unpacked_file, LPSTR result_file)
{
	LPSTR command_line = new CHAR[MAX_PATH];
	ZeroMemory(command_line, MAX_PATH);
	strncpy(command_line, "C:\\Program Files (x86)\\7-Zip\\7z.exe a -tzip ", MAX_PATH - strlen(command_line));
	strncat(command_line, result_file, MAX_PATH - strlen(command_line));
	strncat(command_line, " ", MAX_PATH - strlen(command_line));
	strncat(command_line, unpacked_file, MAX_PATH - strlen(command_line));
	return launch_process(command_line);
}