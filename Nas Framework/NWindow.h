#pragma once
#include "NasWin.h"
#include <vector>

class NWindow
{
protected:
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
		static constexpr const wchar_t* wndClassName = L"Nas Windows Application";
		static WindowClass wndClass;
		HINSTANCE hInstance;
	};

public:
	NWindow(int x, int y, int width, int height, const wchar_t* name, HWND hWndParent) noexcept;
	virtual ~NWindow() noexcept;
	NWindow(const NWindow&) = delete;
	NWindow& operator=(const NWindow&) = delete;

	HWND GetHandle();
	std::vector<HWND> GetChildren();
	int GetWidth() const;
	int GetHeight() const;

protected:
	static LRESULT CALLBACK MessageHandlerSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK MessageHandlerRouter(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT CALLBACK HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:

protected:
	HINSTANCE hInstance;
	HWND hWnd;
	HWND hWndParent;
	std::wstring name;
	std::vector<HWND> children;
	int x;
	int y;
	int width;
	int height;
};