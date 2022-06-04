#pragma once
#include "NasWin.h"
#include <cassert>
#include <commctrl.h>
#include <shlwapi.h> // for common control 
#include <windowsx.h>

// TODO: Fix. This macro is already defined. Now I'm not quite sure what it does.
//// Application is compatible with ComCtl32.dll version 5.81 and later.
//// The application cannot implement features that were added after version 5.81.
//#define _WIN32_IE 0x0501
//#include <commctrl.h>

#define PACKVERSION(major,minor) MAKELONG(minor,major)
DWORD GetVersion(LPCTSTR lpszDllName)
{
	HINSTANCE hinstDll;
	DWORD dwVersion = 0;

	// For security purposes, LoadLibrary should be provided with a fully qualified 
	// path to the DLL. The lpszDllName variable should be tested to ensure that it 
	// is a fully qualified path before it is used. 
	hinstDll = LoadLibrary(lpszDllName);

	if (hinstDll)
	{
		DLLGETVERSIONPROC pDllGetVersion;
		pDllGetVersion = (DLLGETVERSIONPROC)GetProcAddress(hinstDll, "DllGetVersion");

		// Because some DLLs might not implement this function, you must test for 
		// it explicitly. Depending on the particular DLL, the lack of a DllGetVersion 
		// function can be a useful indicator of the version. 

		if (pDllGetVersion)
		{
			DLLVERSIONINFO dvi;
			HRESULT hr;

			ZeroMemory(&dvi, sizeof(dvi));
			dvi.cbSize = sizeof(dvi);

			hr = (*pDllGetVersion)(&dvi);

			if (SUCCEEDED(hr))
			{
				dwVersion = PACKVERSION(dvi.dwMajorVersion, dvi.dwMinorVersion);
			}
		}
		FreeLibrary(hinstDll);
	}
	return dwVersion;
}

int TestCommonControlVersion(int maj, int min)
{
	// TODO: FIX THIS! 
	LPCTSTR lpszDllName = L"C:\\Windows\\System32\\ComCtl32.dll"; // be careful. You could be loading in something malicious here. 
	DWORD dwVer = GetVersion(lpszDllName);
	DWORD dwTarget = PACKVERSION(maj, min);

	if (dwVer >= dwTarget)
	{
		return 1;
		// This version of ComCtl32.dll is version 6.0 or later.
	}
	else
	{
		return 0;
		// Proceed knowing that version 6.0 or later additions are not available.
		// Use an alternate approach for older DLL version.
	}
}

// Loads all common control classes from the DLL
// TODO: separate them into different classes, or provide option to register only certain CC classes, or something else...
class CommonControlManager
{
public:
	CommonControlManager()
	{
		INITCOMMONCONTROLSEX icce = { 0 };
		icce.dwSize = sizeof icce;
		// Load All Classes
		icce.dwICC =
			ICC_ANIMATE_CLASS |
			ICC_BAR_CLASSES |
			ICC_COOL_CLASSES |
			ICC_DATE_CLASSES |
			ICC_HOTKEY_CLASS |
			ICC_INTERNET_CLASSES |
			ICC_LINK_CLASS |
			ICC_LISTVIEW_CLASSES |
			ICC_NATIVEFNTCTL_CLASS |
			ICC_PAGESCROLLER_CLASS |
			ICC_PROGRESS_CLASS |
			ICC_STANDARD_CLASSES |
			ICC_TAB_CLASSES |
			ICC_TREEVIEW_CLASSES |
			ICC_UPDOWN_CLASS |
			ICC_USEREX_CLASSES |
			ICC_WIN95_CLASSES;

		InitCommonControlsEx(&icce);
	}
	std::pair<int, int> GetVersion() const
	{
		// TODO: implement
	}
};