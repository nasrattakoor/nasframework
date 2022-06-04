#pragma once
#include "NasWin.h"
#include "NWindow.h"

class Static : public NWindow
{
public:
	Static(int x, int y, int width, int height, const wchar_t* name, HWND hWndParent)
		:
		NWindow(x, y, width, height, name, hWndParent)
	{
		hWnd = CreateWindowEx(0, L"Static", L"Enter Text Here:", WS_CHILD | WS_VISIBLE, 100, 100, 100, 50, hWndParent, nullptr, nullptr, nullptr); // child windows don't need to specify HINSTANCE
	}

private:
	std::wstring text;
};