// MD5SUM03.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������

// CMD5SUM03App:
// �йش����ʵ�֣������ MD5SUM03.cpp
//

class CFILESHASHApp : public CWinApp
{
public:
	CFILESHASHApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFILESHASHApp theApp;
