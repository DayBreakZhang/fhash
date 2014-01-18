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
// GetProductInfo ����ԭ��(Vista/2008)
typedef BOOL (WINAPI *PGPI)(DWORD, DWORD, DWORD, 
							DWORD, PDWORD );
// �����ǻ�� Windows �汾��Ϣ�Ķ�������
typedef HRESULT (__stdcall *LPFN_DllRegisterServer)(void);
typedef HRESULT (__stdcall *LPFN_DllUnregisterServer)(void);

CString ConvertSizeToCStr(ULONGLONG size);

CString GetExeFileVersion(TCHAR* path);

BOOL GetWindowsVersion(OSVERSIONINFOEX& osvi, BOOL& bOsVersionInfoEx);
CString GetWindowsInfo();
BOOL IsWindows64();
BOOL IsLimitedProc();

bool FindShlExtDll(TCHAR *pszExeFullPath, TCHAR *pszShlDllPath);

bool RegShellExt(TCHAR *pszShlDllPath);
bool UnregShellExt(TCHAR *pszShlDllPath);

bool AddContextMenu(TCHAR *pszExeFullPath);
bool AddShellExt(TCHAR *pszExeFullPath);

bool AddContextMenu();
bool RemoveContextMenu();
bool ContextMenuExisted();
