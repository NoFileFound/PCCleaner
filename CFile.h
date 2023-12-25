#ifndef _CFILE
#define _CFILE
#include<windows.h>

namespace PCCleaner
{
	class CFileManager
	{
		public:
			VOID SendInfoMessage(BOOL);
			VOID RecursiveFolderDeletion(CONST WCHAR*);
	};
}

#endif // _CFILE