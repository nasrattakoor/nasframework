#pragma once
#include <queue>
#include <bitset>

class Keyboard
{
	friend class Window;
public:
    class Event
    {
    public:
		enum class Type
		{
			Press,
			Release,
			Invalid
		};

    public:
        Event( Type type = Type::Invalid,unsigned char code = 0u ) noexcept
			:
			type( type ),
			code( code )
		{}

        bool IsPress() const noexcept
        {
            return type == Type::Press;
        }
        bool IsRelease() const noexcept
        {
            return type == Type::Release;
        }
        bool IsValid() const noexcept
        {
            return type != Type::Invalid;
        }
        unsigned int GetCode() const noexcept
        {
            return code;
        }

    private:
        Type type;
        unsigned int code;
	};

public:
    Keyboard() = default;
    Keyboard( const Keyboard& ) = delete;
	Keyboard& operator=( const Keyboard& ) = delete;

    bool KeyIsPressed(unsigned int keycode) const noexcept;
    bool KeyIsEmpty() const noexcept;
    Event ReadKey() noexcept;
    void FlushKey() noexcept; // clear key queue

    char ReadChar() noexcept;
    bool CharIsEmpty() const noexcept;
    void FlushChar() noexcept;

    void Flush() noexcept; // flush both queues

    // TODO: enable autorepeat control

private: // these functions are meant to be called in Window Procedure
    void OnKeyPress(unsigned int keycode) noexcept;
    void OnKeyRelease(unsigned int keycode) noexcept;
    void OnChar(char character) noexcept;

    void ClearState() noexcept; // clear keystates bitset
    template <typename T>
    void TrimBuffer(std::queue<T>& buffer) noexcept;


private:
    static constexpr unsigned int nKeys = 256u;
    static constexpr unsigned int bufferSize = 16u;
    std::bitset<nKeys> keystates;
    std::queue<Event> keyBuffer;
    std::queue<char> charBuffer;
};
