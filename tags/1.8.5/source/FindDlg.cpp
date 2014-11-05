// FindDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "FilesHash.h"
#include "FindDlg.h"
#include "UIStrings.h"

// CFindDlg �Ի���

IMPLEMENT_DYNAMIC(CFindDlg, CDialog)

CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
	, m_strHash(_T(""))
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HASH, m_strHash);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CFindDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CFindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowText(FINDDLG_TITLE);

	CWnd* pWnd;
	pWnd = GetDlgItem(IDOK);
	pWnd->SetWindowText(BUTTON_OK);
	pWnd = GetDlgItem(IDCANCEL);
	pWnd->SetWindowText(BUTTON_CANCEL);
	pWnd = GetDlgItem(IDC_STATIC_HASH);
	pWnd->SetWindowText(HASHVALUE_STRING);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

// CFindDialog ��Ϣ�������
void CFindDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	OnOK();
}

CString CFindDlg::GetFindHash()
{
	return m_strHash;
}

void CFindDlg::SetFindHash(const CString& str)
{
	m_strHash = str;
}
