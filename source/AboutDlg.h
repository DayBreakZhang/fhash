#pragma once
#include "afxwin.h"

// CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
	DECLARE_DYNAMIC(CAboutDlg)

public:
	CAboutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	CString m_about;

public:
	afx_msg void OnBnClickedOk();
	//CString GetWindowsInfo();

//private:
//	bool AddContextMenu(void);
//	bool RemoveContextMenu(void);
//	bool IsContextMenuAdded(void);
//
//	char exeFullPath[MAX_PATH + 10]; // MAX_PATH
	afx_msg void OnNMClickSyslinkSite(NMHDR *pNMHDR, LRESULT *pResult);
};
