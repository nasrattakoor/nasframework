#include "Window.h"
#include <windowsx.h>
#pragma comment(lib, "d2d1")

Window::WindowClass Window::WindowClass::wndClass; // static member definition

Window::WindowClass::WindowClass() noexcept
{
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof wc;
	wc.style = CS_DBLCLKS | CS_HREDRAW | CS_OWNDC | CS_VREDRAW;
	wc.lpfnWndProc = MessageHandlerSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = wndClass.hInstance;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = wndClassName;

	//wc.hIcon = ;
	//wc.hIconSm ;
	
	// TODO: free icon resource with DestroyIcon
	
	RegisterClassEx(&wc);
}

const wchar_t* Window::WindowClass::GetName() noexcept
{
	return wndClassName;
}

HINSTANCE Window::WindowClass::GetInstance() noexcept
{
	return wndClass.hInstance;
}

Window::WindowClass::~WindowClass() noexcept
{
	UnregisterClass(wndClassName, hInstance);
}

// Window Class Proper

Window::Window(int width, int height, const wchar_t* name) noexcept
    :
	width(width),
	height(height)
{
	RECT wr;
	wr.left = 100;
	wr.right = wr.left + width;
	wr.top = 100;
	wr.bottom = wr.top + height;
	AdjustWindowRectEx(&wr,
		WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_VSCROLL | WS_CAPTION,
		FALSE,
		WS_EX_ACCEPTFILES | WS_EX_CLIENTEDGE
	);
	
	hWnd = CreateWindowEx(
		WS_EX_ACCEPTFILES | WS_EX_CLIENTEDGE, // extended styles
		WindowClass::GetName(), name, // window class and window name
		WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_VSCROLL | WS_CAPTION, // styles
		CW_USEDEFAULT, CW_USEDEFAULT, // window coordinates
		wr.right - wr.left, wr.bottom - wr.top, // window dimensions
		nullptr, nullptr, // handle to parent window and handle to menu
		WindowClass::GetInstance(), this // handle to instance and void* to custom data
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
}

Window::~Window() noexcept
{
	DestroyWindow(hWnd);
}

LRESULT CALLBACK Window::MessageHandlerSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	if (msg == WM_NCCREATE)
	{
		const CREATESTRUCT* const cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		Window* pWnd = reinterpret_cast<Window*>(cs->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(MessageHandlerRouter));
		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::MessageHandlerRouter(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	switch(msg)
	{
		case WM_CREATE:
			if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
			{
				return -1;
			}
			break;
		case WM_CLOSE:
		PostQuitMessage(0);
		break;
		
		/******************* KEYBOARD MESSAGES *******************/
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
		case WM_CHAR:
		/*************** END KEYBOARD MESSAGES *******************/
		/******************** MOUSE MESSAGES *********************/
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_MBUTTONDBLCLK:
		case WM_RBUTTONDBLCLK:
		case WM_MOUSEHOVER:
			break;
		//case WM_PAINT:
		//	PAINTSTRUCT ps;
		//	HDC hdc = BeginPaint(hWnd, &ps);
		//	HBRUSH hbSolid = CreateSolidBrush(RGB(200, 0, 0));
		//	HBRUSH hbHatch = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 200, 0));
		//	FillRect(hdc, &ps.rcPaint, hbHatch);
		//	EndPaint(hWnd, &ps);
		//	break;
		case WM_PAINT:
			//OnPaint();
			break;
		case WM_COMMAND:
		{
			wchar_t lpClassName[128];
			GetClassName((HWND)(lParam), lpClassName, 128);
			if (lpClassName == L"Button")
			{
				Button_SetText(HWND(lParam), L"YO WASSUP");
			}
		}
		/**************** END MOUSE MESSAGES *********************/
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND Window::GetHandle() const
{
	return hWnd;
}

int Window::GetWidth() const
{
	return width;
}

int Window::GetHeight() const
{
	return height;
}
