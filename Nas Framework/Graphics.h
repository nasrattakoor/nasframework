#pragma once
#include "NasWin.h"
#include <d2d1_3.h> // this is newer version of d2d1.h?
#include <cassert>

struct Color
{
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;
};

// NOTE: Draw Calls must be inside calls to BeginDraw and EndDraw

class Graphics
{
public:
	Graphics() = default;
	Graphics(HWND hWnd)
		: hWnd(hWnd)
	{
		// initialize pFactory
		RECT rc;
		GetClientRect(hWnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);
		D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
		// initialize pRenderTarget
		pFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, size),
			&pRenderTarget);
		// initialize pBrush
		pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f), &pBrush);
	}
	~Graphics()
	{
		if (pFactory)		pFactory->Release();
		if (pRenderTarget)	pRenderTarget->Release();
		if (pBrush)			pBrush->Release();
	}

	void NBeginDraw()
	{
		assert(pRenderTarget != nullptr);
		pRenderTarget->BeginDraw();
	}
	void EndDraw()
	{
		pRenderTarget->EndDraw();
	}
	void ClearScreen(Color c)
	{
		pRenderTarget->Clear(D2D1_COLOR_F{ c.r, c.g, c.b });
	}
	void DrawCircle(float x, float y, float radius, Color c)
	{
		pRenderTarget->DrawEllipse(
			D2D1::Ellipse( D2D1::Point2F(x, y), radius, radius ), pBrush );
	}

private:
	HWND hWnd; // render target
				// TODO: signal if hWnd is not initialized

	ID2D1Factory* pFactory = nullptr; // creates render targets and device independent resources
	ID2D1HwndRenderTarget* pRenderTarget = nullptr; // render target that is a window
	ID2D1SolidColorBrush* pBrush = nullptr; // a brush 
};

