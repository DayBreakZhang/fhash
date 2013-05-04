#include "stdafx.h"

const TCHAR *CONTEXT_MENU_ITEM_EN_US = _T("Hash it with fHash");
const TCHAR *CONTEXT_MENU_ITEM_ZH_CN = _T("ʹ�� fHash �����ϣ");

// Multi languages
#define ZH_CN

#ifdef ZH_CN
// Global Strings
const TCHAR *FILE_STRING = _T("�ļ�");
const TCHAR *BYTE_STRING = _T("�ֽ�");
const TCHAR *HASHVALUE_STRING = _T("Hash ֵ:");
const TCHAR *FILENAME_STRING = _T("�ļ���:");
const TCHAR *FILESIZE_STRING = _T("�ļ���С:");
const TCHAR *MODIFYTIME_STRING = _T("�޸�����:");
const TCHAR *VERSION_STRING = _T("�汾:");
const TCHAR *SECOND_STRING = _T("��");
const TCHAR *BUTTON_OK = _T("ȷ��");
const TCHAR *BUTTON_CANCEL = _T("ȡ��");
const TCHAR *CONTEXT_MENU_REGESTRY = _T("*\\shell\\ʹ�� fHash �����ϣ\\command");

// Main Dialog Strings
const TCHAR *MAINDLG_INITINFO = _T("���ļ���������򿪣���ʼ���㡣");
const TCHAR *MAINDLG_CONTEXT_INIT = _T("��Ҫ����ԱȨ��");
const TCHAR *MAINDLG_ADD_SUCCEEDED = _T("��ӳɹ�");
const TCHAR *MAINDLG_ADD_FAILED = _T("���ʧ��");
const TCHAR *MAINDLG_REMOVE_SUCCEEDED = _T("�Ƴ��ɹ�");
const TCHAR *MAINDLG_REMOVE_FAILED = _T("�Ƴ�ʧ��");
const TCHAR *MAINDLG_REMOVE_CONTEXT_MENU = _T("�Ƴ��Ҽ��˵�");
const TCHAR *MAINDLG_ADD_CONTEXT_MENU = _T("����Ҽ��˵�");
const TCHAR *MAINDLG_CLEAR = _T("���(&R)");
const TCHAR *MAINDLG_CLEAR_VERIFY = _T("�����֤(&R)");
const TCHAR *MAINDLG_CALCU_TERMINAL = _T("������ֹ");
const TCHAR *MAINDLG_FIND_IN_RESULT = _T("�ڽ��������");
const TCHAR *MAINDLG_RESULT = _T("ƥ��Ľ��:");
const TCHAR *MAINDLG_NORESULT = _T("��ƥ����");
const TCHAR *MAINDLG_FILE_PROGRESS = _T("�ļ�����");
const TCHAR *MAINDLG_TOTAL_PROGRESS = _T("�������");
const TCHAR *MAINDLG_UPPER_HASH = _T("��д Hash");
const TCHAR *MAINDLG_TIME_TITLE = _T("����ʱ��:");
const TCHAR *MAINDLG_OPEN = _T("��(&O)...");
const TCHAR *MAINDLG_STOP = _T("ֹͣ(&S)");
const TCHAR *MAINDLG_COPY = _T("ȫ������(&C)");
const TCHAR *MAINDLG_VERIFY = _T("��֤(&V)");
const TCHAR *MAINDLG_ABOUT = _T("����(&A)");
const TCHAR *MAINDLG_EXIT = _T("�˳�(&X)");

// Find Dialog Strings
const TCHAR *FINDDLG_TITLE = _T("��֤");

// About Dialog Strings
const TCHAR *ABOUTDLG_TITLE = _T("���� fHash");
const TCHAR *ABOUTDLG_INFO_TITLE = _T("fHash: �ļ� Hash ������ ");
const TCHAR *ABOUTDLG_INFO_RIGHT = _T("Copyright (C) 2007-2013 SUN Junwen.");
const TCHAR *ABOUTDLG_INFO_MD5 = _T("MD5 �㷨���� RSA Data Security, Inc.��д��Copyright (C) RSA Data Security, Inc.");
const TCHAR *ABOUTDLG_INFO_SHA256 = _T("SHA256 �㷨���� Niels Moller ��д��Copyright (C) Niels Moller");
const TCHAR *ABOUTDLG_INFO_CRC32 = _T("CRC32 �㷨���� Dominik Reichl ��д��Copyright (C) Dominik Reichl");
const TCHAR *ABOUTDLG_INFO_RIGHTDETAIL = _T("��ϸ��Ȩ��Ϣ����������վ��");
const TCHAR *ABOUTDLG_INFO_OSTITLE = _T("��ǰ����ϵͳ:");
const TCHAR *ABOUTDLG_PROJECT_SITE = _T("<a>��Ŀ��ҳ</a>");

#else
// Global Strings
const TCHAR *FILE_STRING = _T("File");
const TCHAR *BYTE_STRING = _T("Byte(s)");
const TCHAR *HASHVALUE_STRING = _T("Hash:");
const TCHAR *FILENAME_STRING = _T("Name:");
const TCHAR *FILESIZE_STRING = _T("File Size:");
const TCHAR *MODIFYTIME_STRING = _T("Modified Date:");
const TCHAR *VERSION_STRING = _T("Version:");
const TCHAR *SECOND_STRING = _T("s");
const TCHAR *BUTTON_OK = _T("OK");
const TCHAR *BUTTON_CANCEL = _T("Cancel");
const TCHAR *CONTEXT_MENU_REGESTRY = _T("*\\shell\\Hash it with fHash\\command");

// Main Dialog Strings
const TCHAR *MAINDLG_INITINFO = _T("Drag files here or click open to start calculate.");
const TCHAR *MAINDLG_CONTEXT_INIT = _T("Need Administrator");
const TCHAR *MAINDLG_ADD_SUCCEEDED = _T("Add Succeeded");
const TCHAR *MAINDLG_ADD_FAILED = _T("Add Failed");
const TCHAR *MAINDLG_REMOVE_SUCCEEDED = _T("Remove Succeeded");
const TCHAR *MAINDLG_REMOVE_FAILED = _T("Remove Failed");
const TCHAR *MAINDLG_REMOVE_CONTEXT_MENU = _T("Remove Context Menu");
const TCHAR *MAINDLG_ADD_CONTEXT_MENU = _T("Add to Context Menu");
const TCHAR *MAINDLG_CLEAR = _T("Clea&r");
const TCHAR *MAINDLG_CLEAR_VERIFY = _T("Clea&r Verify");
const TCHAR *MAINDLG_CALCU_TERMINAL = _T("Terminated");
const TCHAR *MAINDLG_FIND_IN_RESULT = _T("Verify");
const TCHAR *MAINDLG_RESULT = _T("Result:");
const TCHAR *MAINDLG_NORESULT = _T("Nothing Found");
const TCHAR *MAINDLG_FILE_PROGRESS = _T("File");
const TCHAR *MAINDLG_TOTAL_PROGRESS = _T("Total");
const TCHAR *MAINDLG_UPPER_HASH = _T("Uppercase");
const TCHAR *MAINDLG_TIME_TITLE = _T("Time Used:");
const TCHAR *MAINDLG_OPEN = _T("&Open...");
const TCHAR *MAINDLG_STOP = _T("&Stop");
const TCHAR *MAINDLG_COPY = _T("&Copy");
const TCHAR *MAINDLG_VERIFY = _T("&Verify");
const TCHAR *MAINDLG_ABOUT = _T("&About");
const TCHAR *MAINDLG_EXIT = _T("E&xit");

// Find Dialog Strings
const TCHAR *FINDDLG_TITLE = _T("Verify");

// About Dialog Strings
const TCHAR *ABOUTDLG_TITLE = _T("About fHash");
const TCHAR *ABOUTDLG_INFO_TITLE = _T("fHash: Files' Hash Calculator ");
const TCHAR *ABOUTDLG_INFO_RIGHT = _T("Copyright (C) 2007-2013 SUN Junwen.");
const TCHAR *ABOUTDLG_INFO_MD5 = _T("MD5 Algorithm is writtend by RSA Data Security, Inc. Copyright (C) RSA Data Security, Inc.");
const TCHAR *ABOUTDLG_INFO_SHA256 = _T("SHA256 Algorithm is writtend by Niels Moller. Copyright (C) Niels Moller");
const TCHAR *ABOUTDLG_INFO_CRC32 = _T("CRC32 Algorithm is writtend by Dominik Reichl. Copyright (C) Dominik Reichl");
const TCHAR *ABOUTDLG_INFO_RIGHTDETAIL = _T("More details are on Project Site.");
const TCHAR *ABOUTDLG_INFO_OSTITLE = _T("Operating System:");
const TCHAR *ABOUTDLG_PROJECT_SITE = _T("<a>Project Home</a>");

#endif
