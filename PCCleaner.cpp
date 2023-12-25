#include "CFile.h"
#define strSize(s) (sizeof(s) / sizeof(s[0]))

INT main()
{
	CONST WCHAR* info[3] = { 
		L"C:\\Windows\\LiveKernelReports\\", 
		L"C:\\Windows\\Temp\\", 
		L"C:\\Windows\\Downloaded Program Files\\"
		L"C:\\Users\\Nikito3301\\AppData\\Local\\Temp\\"
	};

	PCCleaner::CFileManager x;
	x.SendInfoMessage(0);
	while(1)
	{
		if (GetAsyncKeyState(VK_F6) & 0x8000) break;
	}
	if (info != NULL)
	{
		for (SHORT i = 0; i < strSize(info); i++)
		{
			x.RecursiveFolderDeletion(info[i]);
		}
		x.SendInfoMessage(1);
	}
	return 0;
}
