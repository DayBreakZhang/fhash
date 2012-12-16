#define ZH_CN

#ifdef ZH_CN
// Global Strings
const char* FILE_STRING = "�ļ�";
const char* BYTE_STRING = "�ֽ�";
const char* HASHVALUE_STRING = "Hash ֵ:";
const char* FILENAME_STRING = "�ļ���:";
const char* FILESIZE_STRING = "�ļ���С:";
const char* MODIFYTIME_STRING = "�޸�����:";
const char* VERSION_STRING = "�汾:";
const char* SECOND_STRING = "��";
const char* BUTTON_OK = "ȷ��";
const char* BUTTON_CANCEL = "ȡ��";

// Main Dialog Strings
const char* MAINDLG_INITINFO = "���ļ���������򿪣���ʼ���㡣";
const char* MAINDLG_CONTEXT_INIT = "��Ҫ����ԱȨ��";
const char* MAINDLG_ADD_SUCCEEDED = "��ӳɹ�";
const char* MAINDLG_ADD_FAILED = "���ʧ��";
const char* MAINDLG_REMOVE_SUCCEEDED = "�Ƴ��ɹ�";
const char* MAINDLG_REMOVE_FAILED = "�Ƴ�ʧ��";
const char* MAINDLG_REMOVE_CONTEXT_MENU = "�Ƴ��Ҽ��˵�";
const char* MAINDLG_ADD_CONTEXT_MENU = "����Ҽ��˵�";
const char* MAINDLG_CLEAR = "���(&R)";
const char* MAINDLG_CLEAR_VERIFY = "�����֤(&R)";
const char* MAINDLG_CALCU_TERMINAL = "������ֹ";
const char* MAINDLG_FIND_IN_RESULT = "�ڽ��������";
const char* MAINDLG_RESULT = "ƥ��Ľ��:";
const char* MAINDLG_NORESULT = "��ƥ����";
const char* MAINDLG_FILE_PROGRESS = "�ļ�����";
const char* MAINDLG_TOTAL_PROGRESS = "�������";
const char* MAINDLG_UPPER_HASH = "��д Hash";
const char* MAINDLG_TIME_TITLE = "����ʱ��:";
const char* MAINDLG_OPEN = "��(&O)...";
const char* MAINDLG_STOP = "ֹͣ(&S)";
const char* MAINDLG_COPY = "ȫ������(&C)";
const char* MAINDLG_VERIFY = "��֤(&V)";
const char* MAINDLG_ABOUT = "����(&A)";
const char* MAINDLG_EXIT = "�˳�(&X)";

// Find Dialog Strings
const char* FINDDLG_TITLE = "��֤";

// About Dialog Strings
const char* ABOUTDLG_TITLE = "���� fHash";
const char* ABOUTDLG_INFO_TITLE = "fHash: �ļ� Hash ������ ";
const char* ABOUTDLG_INFO_RIGHT = "Copyright (C) 2007-2011 SUN Junwen.";
const char* ABOUTDLG_INFO_MD5 = "MD5 �㷨���� RSA Data Security, Inc.��д��Copyright (C) RSA Data Security, Inc.";
const char* ABOUTDLG_INFO_SHA256 = "SHA256 �㷨���� Niels Moller ��д��Copyright (C) Niels Moller";
const char* ABOUTDLG_INFO_CRC32 = "CRC32 �㷨���� Dominik Reichl ��д��Copyright (C) Dominik Reichl";
const char* ABOUTDLG_INFO_RIGHTDETAIL = "��ϸ��Ȩ��Ϣ����������վ��";
const char* ABOUTDLG_INFO_OSTITLE = "��ǰ����ϵͳ:";
const char* ABOUTDLG_PROJECT_SITE = "<a>��Ŀ��ҳ</a>";

#else
// Global Strings
const char* FILE_STRING = "File";
const char* BYTE_STRING = "Byte(s)";
const char* HASHVALUE_STRING = "Hash:";
const char* FILENAME_STRING = "Name:";
const char* FILESIZE_STRING = "File Size:";
const char* MODIFYTIME_STRING = "Modified Date:";
const char* VERSION_STRING = "Version:";
const char* SECOND_STRING = "s";
const char* BUTTON_OK = "OK";
const char* BUTTON_CANCEL = "Cancel";

// Main Dialog Strings
const char* MAINDLG_INITINFO = "Drag files here or click open to start calculate.";
const char* MAINDLG_CONTEXT_INIT = "Need Administrator";
const char* MAINDLG_ADD_SUCCEEDED = "Add Succeeded";
const char* MAINDLG_ADD_FAILED = "Add Failed";
const char* MAINDLG_REMOVE_SUCCEEDED = "Remove Succeeded";
const char* MAINDLG_REMOVE_FAILED = "Remove Failed";
const char* MAINDLG_REMOVE_CONTEXT_MENU = "Remove Context Menu";
const char* MAINDLG_ADD_CONTEXT_MENU = "Add to Context Menu";
const char* MAINDLG_CLEAR = "Clea&r";
const char* MAINDLG_CLEAR_VERIFY = "Clea&r Verify";
const char* MAINDLG_CALCU_TERMINAL = "Terminated";
const char* MAINDLG_FIND_IN_RESULT = "Verify";
const char* MAINDLG_RESULT = "Result:";
const char* MAINDLG_NORESULT = "Nothing Found";
const char* MAINDLG_FILE_PROGRESS = "File";
const char* MAINDLG_TOTAL_PROGRESS = "Total";
const char* MAINDLG_UPPER_HASH = "Uppercase";
const char* MAINDLG_TIME_TITLE = "Time Used:";
const char* MAINDLG_OPEN = "&Open...";
const char* MAINDLG_STOP = "&Stop";
const char* MAINDLG_COPY = "&Copy";
const char* MAINDLG_VERIFY = "&Verify";
const char* MAINDLG_ABOUT = "&About";
const char* MAINDLG_EXIT = "E&xit";

// Find Dialog Strings
const char* FINDDLG_TITLE = "Verify";

// About Dialog Strings
const char* ABOUTDLG_TITLE = "About fHash";
const char* ABOUTDLG_INFO_TITLE = "fHash: Files' Hash Calculator ";
const char* ABOUTDLG_INFO_RIGHT = "Copyright (C) 2007-2011 SUN Junwen.";
const char* ABOUTDLG_INFO_MD5 = "MD5 Algorithm is writtend by RSA Data Security, Inc. Copyright (C) RSA Data Security, Inc.";
const char* ABOUTDLG_INFO_SHA256 = "SHA256 Algorithm is writtend by Niels Moller. Copyright (C) Niels Moller";
const char* ABOUTDLG_INFO_CRC32 = "CRC32 Algorithm is writtend by Dominik Reichl. Copyright (C) Dominik Reichl";
const char* ABOUTDLG_INFO_RIGHTDETAIL = "More details are on Project Site.";
const char* ABOUTDLG_INFO_OSTITLE = "Operating System:";
const char* ABOUTDLG_PROJECT_SITE = "<a>Project Home</a>";

#endif
