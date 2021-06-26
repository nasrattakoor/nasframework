#include "Mouse.h"

void Mouse::OnMove(int x_in, int y_in) noexcept
{
    x = x_in;
    y = y_in;

    buffer.emplace(Event::Type::Move, *this);
    TrimBuffer();
}

void Mouse::OnLeftPress() noexcept
{
    leftIsPressed = true;
    buffer.emplace(Event::Type::LeftPress, *this);
    TrimBuffer();
}

void Mouse::OnRightPress() noexcept
{
    rightIsPressed = true;
    buffer.emplace(Event::Type::RightPress, *this);
    TrimBuffer();
}

void Mouse::OnMiddlePress() noexcept
{
    middleIsPressed = true;
    buffer.emplace(Event::Type::MiddlePress, *this);
    TrimBuffer();
}

void Mouse::OnLeftRelease() noexcept
{
    leftIsPressed = false;
    buffer.emplace(Event::Type::LeftRelease, *this);
    TrimBuffer();
}

void Mouse::OnRightRelease() noexcept
{
    rightIsPressed = false;
    buffer.emplace(Event::Type::RightRelease, *this);
    TrimBuffer();
}

void Mouse::OnMiddleRelease() noexcept
{
    middleIsPressed = false;
    buffer.emplace(Event::Type::MiddleRelease, *this);
    TrimBuffer();
}

void Mouse::OnLeftDoubleClick() noexcept
{
    buffer.emplace(Event::Type::LeftDoubleClick, *this);
    TrimBuffer();
}

void Mouse::OnRightDoubleClick() noexcept
{
    buffer.emplace(Event::Type::RightDoubleClick, *this);
    TrimBuffer();
}

void Mouse::OnMiddleDoubleClick() noexcept
{
    buffer.emplace(Event::Type::MiddleDoubleClick, *this);
    TrimBuffer();
}

void Mouse::OnExit() noexcept
{
    isInWindow = false;
    buffer.emplace(Event::Type::ExitedWindow, *this);
    TrimBuffer();
}

void Mouse::OnEnter() noexcept
{
    isInWindow = true;
    buffer.emplace(Event::Type::EnteredWindow, *this);
    TrimBuffer();
}

void Mouse::TrimBuffer() noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}
