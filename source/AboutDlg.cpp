// AboutDlg.cpp : ʵ���ļ�
// SUN Junwen

#include "stdafx.h"

#include <atlbase.h>

#include "version.h"
#include "FilesHash.h"
#include "AboutDlg.h"
#include "Functions.h"
#include "UIStrings.h"

// CAboutDlg �Ի���

IMPLEMENT_DYNAMIC(CAboutDlg, CDialog)
CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
	, m_about(_T(""))
{
}

CAboutDlg::~CAboutDlg()
{
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(ABOUTDLG_TITLE); // ���ñ���

	CButton* pButtonOK = (CButton*)GetDlgItem(IDOK);
	pButtonOK->SetWindowText(BUTTON_OK);
	
	CString fHashVersion = STR_VERSION; //GetExeFileVersion(exeFullPath);

	CString osinfo = GetWindowsInfo();
	m_about = ABOUTDLG_INFO_TITLE;
	m_about.Append(fHashVersion);
	m_about.Append("\r\n");
	m_about.Append(ABOUTDLG_INFO_RIGHT);
	m_about.Append("\r\n\r\n");
	m_about.Append(ABOUTDLG_INFO_MD5);
	m_about.Append("\r\n");
	m_about.Append(ABOUTDLG_INFO_SHA256);
	m_about.Append("\r\n");
	m_about.Append(ABOUTDLG_INFO_CRC32);
	m_about.Append("\r\n");
	m_about.Append(ABOUTDLG_INFO_RIGHTDETAIL);
	m_about.Append("\r\n\r\n");

	//m_about = m_about + "��ǰ����ϵͳ:\r\n" + osinfo;
	m_about.Append(ABOUTDLG_INFO_OSTITLE);
	m_about.Append("\r\n");
	m_about.Append(osinfo);

	UpdateData(FALSE);

	return TRUE;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAIN, m_about);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAboutDlg ��Ϣ�������

void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
	EndDialog(0);
}

//bool CAboutDlg::AddContextMenu(void)
//{
//	CRegKey key;
//	LPCSTR lpszKeyName = "*\\shell\\Hash it with fHash\\command";
//	LONG lResult;
//	// ����Ŀ¼
//	lResult = key.Create(HKEY_CLASSES_ROOT, lpszKeyName);
//	if(lResult != ERROR_SUCCESS)
//		return false; // ʧ��
//
//	// ��
//	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
//	if(lResult != ERROR_SUCCESS)
//		return false;
//
//	// �ɹ���
//	char command[270];
//	strcpy_s(command, MAX_PATH + 10, exeFullPath);
//	strcat_s(command, MAX_PATH + 10, " \"%1\"");
//	lResult = key.SetStringValue(NULL, command);
//	key.Close();
//	if(lResult == ERROR_SUCCESS)
//		return true;
//	else
//		return false;
//}
//
//bool CAboutDlg::RemoveContextMenu(void)
//{
//	CRegKey key;
//	LPCSTR lpszKeyName = "*\\shell\\";
//	LONG lResult;
//
//	// ��
//	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
//	if(lResult != ERROR_SUCCESS)
//		return false;
//
//	lResult = key.RecurseDeleteKey("Hash it with fHash");
//	if(lResult != ERROR_SUCCESS)
//		return false;
//	else
//		return true;
//}
//
//bool CAboutDlg::IsContextMenuAdded(void)
//{
//	CRegKey key;
//	LPCSTR lpszKeyName = "*\\shell\\Hash it with fHash\\command";
//	LONG lResult;
//
//	// ��
//	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
//	if(lResult != ERROR_SUCCESS)
//		return false;
//	else
//		return true;
//}

