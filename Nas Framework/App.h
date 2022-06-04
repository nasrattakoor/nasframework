#pragma once
#include "Window.h"
#include "Button.h"

class App
{
public:
	App()
		:
		wnd(800, 600, L"Account Manager"),
		btn(100, 225, 200, 150, wnd.GetHandle(), L"Salaam Alaykum"),
		btn2(500, 225, 200, 150, wnd.GetHandle(), L"Hello")
	{}

	int Go()
	{
		


		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}
		else
		{
			return msg.wParam;
		}
	}

private:
	void DoFrame();
private:
	Window wnd;
	Button btn;
	Button btn2;
};