#include "NasWin.h"

#include <cassert>

#include "Window.h"
#include "CommonControl.h"
#include "Button.h"
#include "WindowMessageMap.h"
#include "Static.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
	assert(TestCommonControlVersion(5, 82)); // version 5.82
	CommonControlManager{};

	NWindow wnd(0, 0, 800, 600, L"Account Manager", nullptr);

	Button btn(100, 225, 200, 150, wnd.GetHandle(), L"Salaam Alaykum");
	Button btn2(500, 225, 200, 150, wnd.GetHandle(), L"Hello");
	Static static1(200, 50, 400, 300, L"static text box 1", nullptr);

	//wnd.gfx.NBeginDraw();
	//wnd.gfx.ClearScreen({ 0.0f,0.0f,0.5f });
	//wnd.gfx.DrawCircle(100, 100, 150, { 1.0f, 0.0f, 0.0f });
	//wnd.gfx.EndDraw();
	WindowsMessageMap mm;

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		OutputDebugStringW(L"HWND\t\tMSG\t\t\t\tLPARAM\t\t\t\tWPARAM\n");
		mm(msg);
		OutputDebugStringW(L"\n");
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