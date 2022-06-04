#pragma once
#include "Window.h"

class Button
{
public:
	Button(int x, int y, int width, int height, HWND parent, const wchar_t* text, 
		DWORD styles = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON)
		:
		x(x),
		y(y),
		width(width),
		height(height),
		hWndParent(parent),
		hInstance((HINSTANCE)(GetWindowLongPtr(parent, GWLP_HINSTANCE))), // why doesn't static_cast work here?
		text(text),
		styles(styles)
	{
		hWnd = 
			CreateWindowEx(
				0,
				L"BUTTON",	// Predefined class; ASCII assumed 
				text,		// Button text 
				styles,		// Styles 
				x,			// x position 
				y,			// y position 
				width,		// Button width
				height,		// Button height
				parent,		// Parent window
				nullptr,	// No menu.
				hInstance,	// Application instance
				this		// Pointer not needed.
			);

		ShowWindow(hWnd, SW_SHOWDEFAULT);
	}

	void SetText(const std::wstring& newText)
	{
		SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)"Wa Alaykum Salaam");
		text = newText;
	}

private:
	int x;
	int y;
	int width;
	int height;
	HWND hWnd;
	HWND hWndParent;
	HINSTANCE hInstance;
	std::wstring text;
	DWORD styles;
};