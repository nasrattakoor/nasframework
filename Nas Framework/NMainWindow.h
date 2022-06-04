#pragma once
#include "NWindow.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class NMainWindow : public NWindow
{
private:
	class WindowClass : public NWindow::WindowClass
	{
		
	};

public:
	NMainWindow(int x, int y, int width, int height, const wchar_t* name, HWND hWndParent)
		:
		NWindow(x, y, width, height, name, nullptr)
	{}
	void SetTitle(const char* title);
	void Resize(int width, int height);
	void Move(int x, int y);

private:
	Keyboard kbd;
	Mouse mouse;
	Graphics gfx;
};