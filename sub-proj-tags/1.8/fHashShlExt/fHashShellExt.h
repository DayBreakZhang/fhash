// fHashShellExt.h : CfHashShellExt ������

#pragma once
#include "resource.h"       // ������

#include "fHashShlExt_i.h"
#include <string>
#include <list>
#include <shlobj.h>
#include "strhelper.h"

typedef std::list<sunjwbase::tstring> TstrList;

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CfHashShellExt

class ATL_NO_VTABLE CfHashShellExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CfHashShellExt, &CLSID_fHashShellExt>,
	//public IDispatchImpl<IfHashShellExt, &IID_IfHashShellExt, &LIBID_fHashShlExtLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit, public IContextMenu 
{
public:
	CfHashShellExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FHASHSHELLEXT)


BEGIN_COM_MAP(CfHashShellExt)
	//COM_INTERFACE_ENTRY(IfHashShellExt)
	//COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	// IShellExtInit
	STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);
	// IContextMenu
	STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
	STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
	STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

private:
	sunjwbase::tstring m_fHashPath;
	TstrList m_pathList;

};

OBJECT_ENTRY_AUTO(__uuidof(fHashShellExt), CfHashShellExt)
