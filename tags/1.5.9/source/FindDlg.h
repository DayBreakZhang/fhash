#pragma once

// CFindDialog �Ի���

class CFindDlg : public CDialog
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindDlg();

// �Ի�������
	enum { IDD = IDD_FIND_DIALOG };

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	CString GetFindHash();
	void SetFindHash(const CString& str);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	CString m_strHash;
	
};
