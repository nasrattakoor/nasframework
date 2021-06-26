#pragma once
#include "NasWin.h"
#include "Keyboard.h"
#include "Mouse.h"

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

private:
    static LRESULT CALLBACK MessageHandlerSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    static LRESULT CALLBACK MessageHandlerRouter(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    LRESULT CALLBACK HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:
    Keyboard kbd;
    Mouse mouse;

private:
    HWND hWnd;
    int width;
    int height;
};