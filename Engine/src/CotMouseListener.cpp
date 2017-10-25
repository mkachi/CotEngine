#include "input/CotMouseListener.h"
#include "input/CotInputManager.h"

namespace Cot
{
	MouseListener::MouseListener()
	{
		_wnd = InputManager::GetInstance().GetHandle();
	}

	MouseListener::~MouseListener()
	{	}

	Vec2 MouseListener::GetMousePosition()
	{
		POINT point;
		GetCursorPos(&point);
		ScreenToClient(_wnd, &point);
		return Vec2(point.x, point.y);
	}

	bool MouseListener::IsMouseDown(MouseButton code)
	{
		if (_mouseDownQueue.empty())
		{
			return false;
		}

		MouseButton temp = _mouseDownQueue.front();
		if (temp == code)
		{
			_mouseDownQueue.pop();
			return true;
		}
		return false;
	}

	bool MouseListener::IsMouseUp(MouseButton code)
	{
		if (_mouseUpQueue.empty())
		{
			return false;
		}

		MouseButton temp = _mouseUpQueue.front();
		if (temp == code)
		{
			_mouseUpQueue.pop();
			return true;
		}
		return false;
	}

	bool MouseListener::IsMouseStay(MouseButton code)
	{
		return _mouseState[(uint)code];
	}

	void MouseListener::UpdateKeyDown(uint key)
	{
		_mouseState[key] = true;
		_mouseDownQueue.push((MouseButton)key);
	}

	void MouseListener::UpdateKeyUp(uint key)
	{
		_mouseState[key] = false;
		_mouseUpQueue.push((MouseButton)key);
	}

	void MouseListener::Clear()
	{
		CLEAR_QUEUE(_mouseDownQueue);
		CLEAR_QUEUE(_mouseUpQueue);
	}
}