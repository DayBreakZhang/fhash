// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// MD5SUM03.pch ����Ԥ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// Fix so big binary
// this is our own local copy of the AfxLoadSystemLibraryUsingFullPath function
HMODULE AfxLoadSystemLibraryUsingFullPath(const WCHAR *pszLibrary)
{
	WCHAR wszLoadPath[MAX_PATH+1];
	if (::GetSystemDirectoryW(wszLoadPath, _countof(wszLoadPath)) == 0)
	{
		return NULL;
	}

	if (wszLoadPath[wcslen(wszLoadPath)-1] != L'\\')
	{
		if (wcscat_s(wszLoadPath, _countof(wszLoadPath), L"\\") != 0)
		{
			return NULL;
		}
	}

	if (wcscat_s(wszLoadPath, _countof(wszLoadPath), pszLibrary) != 0)
	{
		return NULL;
	}

	return(::AfxCtxLoadLibraryW(wszLoadPath));
}


