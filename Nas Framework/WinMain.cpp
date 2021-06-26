#include "NasWin.h"

#include <cassert>

#include "Window.h"
#include "CommonControl.h"
#include "Button.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
	assert(TestCommonControlVersion(5, 82)); // version 5.82
	CommonControlManager{};

	Window wnd(800, 600, L"NasTech Account Manager");

	Button btn(100, 225, 200, 150, wnd.GetHandle(), L"Salaam Alaykum");
	Button btn2(500, 225, 200, 150, wnd.GetHandle(), L"Hello");

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