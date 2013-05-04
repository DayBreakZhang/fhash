#pragma once
#include "stdafx.h"

#include "strhelper.h"

inline sunjwbase::tstring cstrtotstr(const CString& cstring)
{
	return sunjwbase::tstring(cstring.GetString());
}

inline CString tstrtocstr(const sunjwbase::tstring& tstr)
{
	CString temp;
	temp.SetString(tstr.c_str());
	return temp;
}

// �����ǻ�� Windows �汾��Ϣ�Ķ�������
#define BUFSIZE 80

typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
// GetProductInfo����ԭ��(Vista/2008)
typedef BOOL (WINAPI *PGPI)(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
// �����ǻ�� Windows �汾��Ϣ�Ķ�������

CString ConvertSizeToCStr(ULONGLONG size);

CString GetExeFileVersion(TCHAR* path);

BOOL GetWindowsVersion(OSVERSIONINFOEX& osvi, BOOL& bOsVersionInfoEx);

CString GetWindowsInfo();

bool AddContextMenu(void);
bool RemoveContextMenu(void);
bool ContextMenuExisted(void);
