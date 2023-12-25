#include "CFile.h"
#include<stdio.h>
using namespace PCCleaner;

VOID 
CFileManager::SendInfoMessage(
    BOOL type
)
{
	if (!type)
	{
		printf("[#] Simple pc cleaner. Made in early 2020 by Nikito3301.You may need use admin privileges.\nPress F6 key to start.\n");
	}
	else
	{
		printf("[#] Done. Have a nice day!\n");
	}
}

VOID 
CFileManager::RecursiveFolderDeletion(
    CONST WCHAR* folderPath
)
{
	WCHAR currentDir[MAX_PATH] = { 0 };

	lstrcpyW(currentDir, folderPath);
	lstrcatW(currentDir, L"*.*");

	WIN32_FIND_DATA findData;
	HANDLE hFile = FindFirstFileW(currentDir, &findData);
	if (hFile == INVALID_HANDLE_VALUE)
		return;
	do
	{
		if (!lstrcmpW(findData.cFileName, L".") || !lstrcmpW(findData.cFileName, L".."))
		{
			continue;
		}
		else if (findData.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)
		{
			continue;
		}
		else
		{
			WCHAR currentFile[MAX_PATH] = { 0 };
			lstrcpyW(currentFile, folderPath);
			lstrcatW(currentFile, findData.cFileName);
			printf("[#] Found a file path --> %ws\n", currentFile);
			if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // if is a directory
			{
				lstrcatW(currentFile, L"\\");
				RecursiveFolderDeletion(currentFile);
			}
			else
			{
				DeleteFileW(currentFile);
			}
		}
	}
	while (FindNextFileW(hFile, &findData));
	FindClose(hFile);
	RemoveDirectoryW(folderPath);
}