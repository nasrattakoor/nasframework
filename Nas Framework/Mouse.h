#pragma once
#include <queue>

class Mouse
{
    friend class Window;
private:
    class Event
    {
    public:
		enum class Type
		{
			Move,
			LeftPress,
			LeftRelease,
			RightPress,
			RightRelease,
			MiddlePress,
			MiddleRelease,
			LeftDoubleClick,
			RightDoubleClick,
			MiddleDoubleClick,
			EnteredWindow,
			ExitedWindow,
			Invalid
		};

    public:
        Event(Type type, const Mouse& parent)
            :
            x(parent.x),
            y(parent.y),
            leftIsPressed(parent.leftIsPressed),
            rightIsPressed(parent.rightIsPressed),
            middleIsPressed(parent.middleIsPressed),
            type(type)
        {}

        Type GetType() const noexcept
        {
            return type;
        }
        std::pair<int, int> GetPos() const noexcept
        {
            return {x, y};
        }
        int GetPosX() const noexcept
        {
            return x;
        }
        int GetPosY() const noexcept
        {
            return y;
        }

    private:
        Type type;
        int x;
        int y;
        bool leftIsPressed;
        bool rightIsPressed;
        bool middleIsPressed;
	};

public:
    Event Read() noexcept
    {
        auto e = buffer.front();
        buffer.pop();
        return e;
    }
    std::pair<int, int> GetPos() const noexcept
    {
        return {x, y};
    }
    int GetPosX() const noexcept
    {
        return x;
    }
    int GetPosY() const noexcept
    {
        return y;
    }
    bool LeftIsPressed() const noexcept
    {
        return leftIsPressed;
    }
    bool RightIsPressed() const noexcept
    {
        return rightIsPressed;
    }
    bool MiddleIsPressed() const noexcept
    {
        return middleIsPressed;
    }
    bool IsInWindow() const noexcept
    {
        return isInWindow;
    }

private:
    void OnMove(int x, int y) noexcept;
    void OnLeftPress() noexcept;
    void OnRightPress() noexcept;
    void OnMiddlePress() noexcept;
    void OnLeftRelease() noexcept;
    void OnRightRelease() noexcept;
    void OnMiddleRelease() noexcept;
    void OnLeftDoubleClick() noexcept;
    void OnRightDoubleClick() noexcept;
    void OnMiddleDoubleClick() noexcept;
    void OnExit() noexcept;
    void OnEnter() noexcept;

	void TrimBuffer() noexcept;

private:
    static constexpr unsigned int bufferSize = 16u;
    std::queue<Event> buffer;
    int x;
    int y;
    bool leftIsPressed;
    bool rightIsPressed;
    bool middleIsPressed;
    bool isInWindow;
};