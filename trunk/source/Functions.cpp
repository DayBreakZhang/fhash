#include "stdafx.h"

#include <atlbase.h>

#include "Functions.h"

CString ConvertSizeToCStr(ULONGLONG size)
{
	CString strSize(_T(""));

	if(size > 1024)
	{
		float k_fsize = size / 1024.0f;
		if(k_fsize > 1024)
		{
			float M_fsize = k_fsize / 1024;
			if(M_fsize > 1024)
			{
				float g_fsize = M_fsize / 1024;
				strSize.Format(" (%.2f GB)", g_fsize);
			}
			else
				strSize.Format(" (%.2f MB)", M_fsize);
		}
		else
			strSize.Format(" (%.2f KB)", k_fsize);
	}

	return strSize;
}

/*
 * GetExeFileVersion
 * ���ָ��·���ļ��汾
 * ��ʽ��Ϊ ���汾��.���汾��.�Ͱ汾��.����汾��
 * ����ļ�û�а汾�ţ�����""
 */
CString GetExeFileVersion(char* path)
{
	// get file version //

	CString Ver = "";
	unsigned int MVer,SVer,LVer,BVer;
	VS_FIXEDFILEINFO pvsf;
	DWORD dwHandle;
	DWORD cchver = GetFileVersionInfoSize(path, &dwHandle);
	char pver[5000];
	BOOL bret = GetFileVersionInfo(path, dwHandle, cchver, pver);
	if(1==bret)
	{
		UINT uLen;
		void *pbuf;
		bret = VerQueryValue(pver, "\\", &pbuf, &uLen);
		memcpy(&pvsf, pbuf, sizeof(VS_FIXEDFILEINFO));

		// ���汾��ת��Ϊ���� //
		MVer = pvsf.dwFileVersionMS / 65536;
		SVer = pvsf.dwFileVersionMS - 65536 * MVer;
		LVer = pvsf.dwFileVersionLS / 65536;
		BVer = pvsf.dwFileVersionLS - 65536 * LVer;
		Ver.Format("%d.%d.%d.%d", MVer, SVer, LVer, BVer);
		// ���汾��ת��Ϊ���� //
	}

	// get file version //
	return Ver;
}

BOOL GetWindowsVersion(OSVERSIONINFOEX& osvi, BOOL& bOsVersionInfoEx)
{
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	// Try calling GetVersionEx using the OSVERSIONINFOEX structure.
	// If that fails, try using the OSVERSIONINFO structure.

	if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	{
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
			return FALSE;
	}

	return TRUE;
}

/*
 * GetWindowsInfo()
 * ��� Windows �汾��Ϣ
 */
CString GetWindowsInfo()
{
	CString osinfo="";

	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	PGNSI pGNSI;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));

	GetWindowsVersion(osvi, bOsVersionInfoEx);

	// Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.

	pGNSI = (PGNSI) GetProcAddress(
		GetModuleHandle(TEXT("kernel32.dll")), 
		"GetNativeSystemInfo");
	if(NULL != pGNSI)
		pGNSI(&si);
	else GetSystemInfo(&si);

	switch (osvi.dwPlatformId)
	{
		// Test for the Windows NT product family.

	case VER_PLATFORM_WIN32_NT:

		// Test for the specific product.
		if(osvi.dwMajorVersion > 6)
		{
			osinfo.AppendFormat(_T("Windows Version %d"), osvi.dwMajorVersion);
		}

		if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1 )
		{
			if( osvi.wProductType == VER_NT_WORKSTATION )
				osinfo.Append(_T("Windows 7 "));
			else 
				osinfo.Append(_T("Windows Server \"Longhorn\" "));
		}

		if ( osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0 )
		{
			if( osvi.wProductType == VER_NT_WORKSTATION )
				osinfo.Append(_T("Windows Vista "));
			else 
				osinfo.Append(_T("Windows Server \"Longhorn\" "));
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 )
		{
			if( osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)
			{
				osinfo.Append(_T("Microsoft Windows XP Professional x64 Edition "));
			}
			else 
				osinfo.Append(_T("Microsoft Windows Server 2003, "));
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
		{	
			osinfo.Append(_T("Microsoft Windows XP "));
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
			osinfo.Append(_T("Microsoft Windows 2000 "));

		if ( osvi.dwMajorVersion <= 4 )
			osinfo.Append(_T("Microsoft Windows NT "));

		///osvi.dwMajorVersion = 6;

		if(osvi.dwMajorVersion != 6)
		{
			if(  osvi.wSuiteMask & VER_SUITE_PERSONAL )
				osinfo.Append(_T( "Home Edition "));
			else osinfo.Append(_T( "Professional "));
		}
		else
		{
			// ���GetProductInfo����ԭ��
			PGPI   pGetProductInfo  = NULL;
			pGetProductInfo = (PGPI) GetProcAddress( GetModuleHandle(TEXT("kernel32.dll")), "GetProductInfo");
			if( pGetProductInfo != NULL )
			{
				DWORD dwProductType = 0;
				(*pGetProductInfo)( 6,0,0,0,&dwProductType);
				switch( dwProductType )
				{
				case PRODUCT_ULTIMATE:
				case PRODUCT_ULTIMATE_N:
					osinfo.Append(_T("Ultimate Edition "));
					break;
				case PRODUCT_HOME_PREMIUM:
				case PRODUCT_HOME_PREMIUM_N:
					osinfo.Append(_T("Home Premium Edition "));
					break;
				case PRODUCT_HOME_BASIC:
				case PRODUCT_HOME_BASIC_N:
					osinfo.Append(_T("Home Basic Edition "));
					break;
				case PRODUCT_HOME_SERVER:
					osinfo.Append(_T("Home Server Edition "));
					break;
				case PRODUCT_ENTERPRISE:
				case PRODUCT_ENTERPRISE_N:
					osinfo.Append(_T("Enterprise Edition "));
					break;
				case PRODUCT_BUSINESS:
				case PRODUCT_BUSINESS_N:
					osinfo.Append(_T("Business Edition "));
					break;
				case PRODUCT_STARTER:
					osinfo.Append(_T("Starter Edition "));
					break;
				case PRODUCT_CLUSTER_SERVER:
					osinfo.Append(_T("Cluster Server Edition "));
					break;
				case PRODUCT_DATACENTER_SERVER:
					osinfo.Append(_T("Datacenter Edition "));
					break;
				case PRODUCT_DATACENTER_SERVER_CORE:
					osinfo.Append(_T("Datacenter Edition (core installation) "));
					break;
				case PRODUCT_ENTERPRISE_SERVER:
					osinfo.Append(_T("Enterprise Edition"));
					break;
				case PRODUCT_ENTERPRISE_SERVER_CORE:
					osinfo.Append(_T("Enterprise Edition (core installation) "));
					break;
				case PRODUCT_ENTERPRISE_SERVER_IA64:
					osinfo.Append(_T("Enterprise Edition for Itanium-based Systems "));
					break;
				case PRODUCT_SMALLBUSINESS_SERVER:
					osinfo.Append(_T("Small Business Server "));
					break;
				case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
					osinfo.Append(_T("Small Business Server Premium Edition "));
					break;
				case  PRODUCT_SERVER_FOR_SMALLBUSINESS:
					osinfo.Append(_T("Server for Small Business Edition "));
					break;
				case PRODUCT_STANDARD_SERVER:
					osinfo.Append(_T("Standard Edition "));
					break;
				case PRODUCT_STANDARD_SERVER_CORE:
					osinfo.Append(_T("Standard Edition (core installation) "));
					break;
				case PRODUCT_WEB_SERVER:
					osinfo.Append(_T("Web Server Edition "));
					break;
				case PRODUCT_WEB_SERVER_CORE:
					osinfo.Append(_T("Web Server Edition (core installation) "));
					break;
				case PRODUCT_STORAGE_ENTERPRISE_SERVER:
					osinfo.Append(_T("Storage Server Enterprise Edition "));
					break;
				case PRODUCT_STORAGE_EXPRESS_SERVER:
					osinfo.Append(_T("Storage Server Express Edition "));
					break;
				case PRODUCT_STORAGE_STANDARD_SERVER:
					osinfo.Append(_T("Storage Server Standard Edition "));
					break;
				case PRODUCT_STORAGE_WORKGROUP_SERVER:
					osinfo.Append(_T("Storage Server Workgroup Edition "));
					break;
				case PRODUCT_UNLICENSED:
					osinfo.Append(_T("Unlicensed Edition "));
					break;
				default:
					osinfo.Append(_T("Unknown Edition "));
					break;
				}
			}
		}

		// Test for specific product on Windows NT 4.0 SP6 and later.
		if( bOsVersionInfoEx )
		{
			// Test for the workstation type.
			if ( osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture!=PROCESSOR_ARCHITECTURE_AMD64)
			{
				if( osvi.dwMajorVersion == 4 )
					osinfo.Append(_T( "Workstation 4.0 "));
			}

			// Test for the server type.
			else if ( osvi.wProductType == VER_NT_SERVER || 
				osvi.wProductType == VER_NT_DOMAIN_CONTROLLER )
			{
				if(osvi.dwMajorVersion==5 && osvi.dwMinorVersion==2)
				{
					if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64 )
					{
						if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
							osinfo.Append(_T( "Datacenter Edition for Itanium-based Systems"));
						else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
							osinfo.Append(_T( "Enterprise Edition for Itanium-based Systems"));
					}

					else if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64 )
					{
						if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
							osinfo.Append(_T( "Datacenter x64 Edition "));
						else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
							osinfo.Append(_T( "Enterprise x64 Edition "));
						else osinfo.Append(_T( "Standard x64 Edition "));
					}

					else
					{
						if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
							osinfo.Append(_T( "Datacenter Edition "));
						else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
							osinfo.Append(_T( "Enterprise Edition "));
						else if ( osvi.wSuiteMask & VER_SUITE_BLADE )
							osinfo.Append(_T( "Web Edition "));
						else osinfo.Append(_T( "Standard Edition "));
					}
				}
				else if(osvi.dwMajorVersion==5 && osvi.dwMinorVersion==0)
				{
					if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						osinfo.Append(_T( "Datacenter Server "));
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						osinfo.Append(_T( "Advanced Server "));
					else osinfo.Append(_T( "Server "));
				}
				else  // Windows NT 4.0 
				{
					if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						osinfo.Append(_T("Server 4.0, Enterprise Edition "));
					else osinfo.Append(_T( "Server 4.0 "));
				}
			}
		}
		// Test for specific product on Windows NT 4.0 SP5 and earlier
		else  
		{
			HKEY hKey;
			TCHAR szProductType[BUFSIZE];
			DWORD dwBufLen=BUFSIZE*sizeof(TCHAR);
			LONG lRet;

			lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
				TEXT("SYSTEM\\CurrentControlSet\\Control\\ProductOptions"),
				0, KEY_QUERY_VALUE, &hKey );
			if( lRet != ERROR_SUCCESS )
				return FALSE;

			lRet = RegQueryValueEx( hKey, TEXT("ProductType"), NULL, NULL,
				(LPBYTE) szProductType, &dwBufLen);
			RegCloseKey( hKey );

			if( (lRet != ERROR_SUCCESS) || (dwBufLen > BUFSIZE*sizeof(TCHAR)) )
				return FALSE;

			if ( lstrcmpi( TEXT("WINNT"), szProductType) == 0 )
				osinfo.Append(_T( "Workstation "));
			if ( lstrcmpi( TEXT("LANMANNT"), szProductType) == 0 )
				osinfo.Append(_T( "Server "));
			if ( lstrcmpi( TEXT("SERVERNT"), szProductType) == 0 )
				osinfo.Append(_T( "Advanced Server "));
			CString verinfo;
			verinfo.Format("%d.%d ", osvi.dwMajorVersion, osvi.dwMinorVersion );
			osinfo.Append(verinfo);
		}

		// Display service pack (if any) and build number.

		if( osvi.dwMajorVersion == 4 && 
			lstrcmpi( osvi.szCSDVersion, TEXT("Service Pack 6") ) == 0 )
		{ 
			HKEY hKey;
			LONG lRet;

			// Test for SP6 versus SP6a.
			lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
				TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009"),
				0, KEY_QUERY_VALUE, &hKey );
			if( lRet == ERROR_SUCCESS )
			{
				CString spinfo;
				spinfo.Format("Service Pack 6a (Build %d)\r\n", 
								osvi.dwBuildNumber & 0xFFFF ); 
				osinfo.Append(spinfo); 
			}
			else // Windows NT 4.0 prior to SP6a
			{
				CString spinfo;
				spinfo.Format( TEXT("%s (Build %d)\r\n"),
					osvi.szCSDVersion,
					osvi.dwBuildNumber & 0xFFFF);
				osinfo.Append(spinfo);
			}

			RegCloseKey( hKey );
		}
		else // not Windows NT 4.0 
		{
			CString spinfo;
			spinfo.Format(TEXT("%s (Build %d)\r\n"),
				osvi.szCSDVersion,
				osvi.dwBuildNumber & 0xFFFF);
			osinfo.Append(spinfo);
		}

		break;

		// Test for the Windows Me/98/95.
	case VER_PLATFORM_WIN32_WINDOWS:

		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
		{
			osinfo.Append(_T("Microsoft Windows 95 "));
			if (osvi.szCSDVersion[1]=='C' || osvi.szCSDVersion[1]=='B')
				osinfo.Append(_T("OSR2 "));
		} 

		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10)
		{
			osinfo.Append(_T("Microsoft Windows 98 "));
			if ( osvi.szCSDVersion[1]=='A' || osvi.szCSDVersion[1]=='B')
				osinfo.Append(_T("SE "));
		} 

		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90)
		{
			osinfo.Append(_T("Microsoft Windows Millennium Edition\r\n"));
		} 
		break;

	case VER_PLATFORM_WIN32s:

		osinfo.Append(_T("Microsoft Win32s\r\n"));
		break;
	}
	return osinfo; 
}

bool AddContextMenu(void)
{
	char exeFullPath[MAX_PATH + 10]; // MAX_PATH
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);//�õ�����ģ�����ƣ�ȫ·��

	CRegKey key;
	LPCSTR lpszKeyName = "*\\shell\\Hash it with fHash\\command";
	LONG lResult;
	// ����Ŀ¼
	lResult = key.Create(HKEY_CLASSES_ROOT, lpszKeyName);
	if(lResult != ERROR_SUCCESS)
		return false; // ʧ��

	// ��
	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
	if(lResult != ERROR_SUCCESS)
		return false;

	// �ɹ���
	char command[270];
	strcpy_s(command, MAX_PATH + 10, exeFullPath);
	strcat_s(command, MAX_PATH + 10, " \"%1\"");
	lResult = key.SetStringValue(NULL, command);
	key.Close();
	if(lResult == ERROR_SUCCESS)
		return true;
	else
		return false;
}

bool RemoveContextMenu(void)
{
	CRegKey key;
	LPCSTR lpszKeyName = "*\\shell\\";
	LONG lResult;

	// ��
	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
	if(lResult != ERROR_SUCCESS)
		return false;

	lResult = key.RecurseDeleteKey("Hash it with fHash");
	if(lResult != ERROR_SUCCESS)
		return false;
	else
		return true;
}

bool IsContextMenuAdded(void)
{
	CRegKey key;
	LPCSTR lpszKeyName = "*\\shell\\Hash it with fHash\\command";
	LONG lResult;

	// ��
	lResult = key.Open(HKEY_CLASSES_ROOT, lpszKeyName, KEY_ALL_ACCESS);
	if(lResult != ERROR_SUCCESS)
		return false;
	else
		return true;
}

