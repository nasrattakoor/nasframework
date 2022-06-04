#pragma once
#include "NasWin.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

// Direct2D interfaces
#include <d2d1.h>

class Window
{
private:
    class WindowClass
    {
    public:
        WindowClass() noexcept;
        ~WindowClass() noexcept;
        WindowClass(const WindowClass&) = delete;
        WindowClass& operator=(const WindowClass&) = delete;

        static const wchar_t* GetName() noexcept;
        static HINSTANCE GetInstance() noexcept;

    private:
        static constexpr const wchar_t* wndClassName = L"Nasrat Windows Application";
        static WindowClass wndClass;
        HINSTANCE hInstance;
	};

public:
    Window(int width, int height, const wchar_t* name) noexcept;
    ~Window() noexcept;
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

	HWND GetHandle() const;
	int GetWidth() const;
	int GetHeight() const;

    void SetTitle(const char* title);
    void Resize(int width, int height);
    void Move(int x, int y);

	/**************** Direct2D functions ****************/
	//template <class T> void SafeRelease(T **ppT)
	//{
	//	if (*ppT)
	//	{
	//		(*ppT)->Release();
	//		*ppT = NULL;
	//	}
	//}
	//HRESULT CreateGraphicsResources()
	//{
	//	HRESULT hr = S_OK;
	//	if (!pRenderTarget)
	//	{
	//		RECT rc;
	//		GetClientRect(hWnd, &rc);
	//		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
	//
	//		hr = pFactory->CreateHwndRenderTarget(
	//			D2D1::RenderTargetProperties(), 
	//			D2D1::HwndRenderTargetProperties(hWnd, size), 
	//			&pRenderTarget);
	//
	//		if (SUCCEEDED(hr))
	//		{
	//			const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0.0f);
	//			hr = pRenderTarget->CreateSolidColorBrush(color, &pBrush);
	//
	//			if (SUCCEEDED(hr))
	//			{
	//				CalculateLayout();
	//			}
	//		}
	//	}
	//	return hr;
	//}
	//void DiscardGraphicsResources()
	//{
	//	SafeRelease(&pRenderTarget);
	//	SafeRelease(&pBrush);
	//}
	//void OnPaint()
	//{
	//	HRESULT hr = CreateGraphicsResources();
	//	if (SUCCEEDED(hr))
	//	{
	//		PAINTSTRUCT ps;
	//		BeginPaint(hWnd, &ps);
	//		pRenderTarget->BeginDraw();
	//		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));
	//		pRenderTarget->FillEllipse(&ellipse, pBrush);
	//		hr = pRenderTarget->EndDraw();
	//		if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET) // while prgm is running, device /might/ become unavailable. In that case, the render target is also invalidated, along with/ /any device-dependent resources associated with the device. This is signaled by //D2DERR_RECREATE_TARGET return value. If you receive this error code, you must re-/create the/ render target and all device-dependent resources.
	//		{
	//			DiscardGraphicsResources();
	//		}
	//		EndPaint(hWnd, &ps);
	//	}
	//}
	//void CalculateLayout()
	//{
	//	if (pRenderTarget != NULL)
	//	{
	//		D2D1_SIZE_F size = pRenderTarget->GetSize();
	//		const float x = size.width / 2;
	//		const float y = size.height / 2;
	//		const float radius = std::min(x, y);
	//		ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
	//	}
	//}
	//void Resize()
	//{
	//	if (pRenderTarget != nullptr)
	//	{
	//		RECT rc;
	//		GetClientRect(hWnd, &rc);
	//
	//		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
	//
	//		pRenderTarget->Resize(size);
	//		CalculateLayout();
	//		InvalidateRect(hWnd, nullptr, FALSE);
	//	}
	//}
	/****************** END DIRECT2D FUNCTIONS ******************/

private:
    static LRESULT CALLBACK MessageHandlerSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    static LRESULT CALLBACK MessageHandlerRouter(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    LRESULT CALLBACK HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:
    Keyboard kbd;
    Mouse mouse;
	//Graphics gfx;

private:
    HWND hWnd;
	std::vector<HWND> children;
    int width;
    int height;


	// Direct 2D resources
	ID2D1Factory* pFactory = nullptr; // creates render targets and device independent resources
	ID2D1HwndRenderTarget* pRenderTarget = nullptr; // render target that is a window
	ID2D1SolidColorBrush* pBrush = nullptr; // a brush 
	D2D1_ELLIPSE ellipse;
};