#include "Keyboard.h"

bool Keyboard::KeyIsPressed(unsigned int keycode) const noexcept
{
    return keystates[keycode];
}

bool Keyboard::KeyIsEmpty() const noexcept
{
    return keyBuffer.empty();
}

Keyboard::Event Keyboard::ReadKey() noexcept
{
	auto e = keyBuffer.front();
    keyBuffer.pop();
    return e;
}

void Keyboard::FlushKey() noexcept
{
    keyBuffer = std::queue<Event>();
}

// TODO: implement std::optional - you don't want to assume 0 is invalid value for char
char Keyboard::ReadChar() noexcept
{
    if (charBuffer.size() > 0u)
    {
        auto e = charBuffer.front();
        charBuffer.pop();
        return e;
    }
    return {};
}

bool Keyboard::CharIsEmpty() const noexcept
{
    return charBuffer.empty();
}

void Keyboard::FlushChar() noexcept
{
    charBuffer = std::queue<char>();
}

void Keyboard::Flush() noexcept
{
    FlushKey();
    FlushChar();
}







void Keyboard::OnKeyPress(unsigned int keycode) noexcept
{
    keystates[keycode] = true;
	keyBuffer.emplace(Event::Type::Press, keycode);
    TrimBuffer(keyBuffer);
}

void Keyboard::OnKeyRelease(unsigned int keycode) noexcept
{
    keystates[keycode] = false;
    keyBuffer.emplace(Event::Type::Release, keycode);
    TrimBuffer(keyBuffer);
}

void Keyboard::OnChar(char character) noexcept
{
    charBuffer.push(character);
    TrimBuffer(charBuffer);
}

void Keyboard::ClearState() noexcept
{
    keystates.reset();
}

template <typename T>
void Keyboard::TrimBuffer(std::queue<T>& buffer) noexcept
{
    while(buffer.size() > bufferSize)
    {
        buffer.pop();
    }
}
