#include "input/CotInputDevice.h"

namespace Cot
{
	InputDevice::InputDevice(HWND wnd)
		: _wnd(wnd)
	{
		for (int i = 0; i < (uint)KeyCode::KEYBOARD_END; ++i)
		{
			_keyStayState[i] = false;
			_keyDownState[i] = false;
			_keyUpState[i] = false;
		}
	}

	InputDevice::~InputDevice()
	{	}

	bool InputDevice::IsKeyDown(KeyCode code)
	{
		if (_keyStayState[(uint)code])
		{
			return false;
		}

		return _keyDownState[(uint)code];
	}

	bool InputDevice::IsKeyUp(KeyCode code)
	{
		return _keyUpState[(uint)code];
	}

	bool InputDevice::IsKeyStay(KeyCode code)
	{
		return _keyStayState[(uint)code];
	}

	void InputDevice::UpdateKeyDown(uint key)
	{
		KeyCode code = ToCotKeyCode(key);
		_keyDownState[(uint)code] = true;
		_keyUpState[(uint)code] = false;
	}

	void InputDevice::UpdateKeyUp(uint key)
	{
		KeyCode code = ToCotKeyCode(key);
		_keyDownState[(uint)code] = false;
		_keyStayState[(uint)code] = false;
		_keyUpState[(uint)code] = true;
	}

	bool InputDevice::IsMouseDown(MouseButton button)
	{
		if (_mouseStayState[(uint)button])
		{
			return false;
		}

		return _mouseDownState[(uint)button];
	}

	bool InputDevice::IsMouseStay(MouseButton button)
	{
		return _mouseStayState[(uint)button];
	}

	bool InputDevice::IsMouseUp(MouseButton button)
	{
		return _mouseUpState[(uint)button];
	}

	Vec2 InputDevice::GetMousePosition()
	{
		POINT point;
		GetCursorPos(&point);
		ScreenToClient(_wnd, &point);
		return Vec2(point.x, point.y);
	}

	void InputDevice::UpdateMouseDown(MouseButton button)
	{
		_mouseDownState[(uint)button] = true;
		_mouseUpState[(uint)button] = false;
	}

	void InputDevice::UpdateMouseUp(MouseButton button)
	{
		_mouseDownState[(uint)button] = false;
		_mouseStayState[(uint)button] = false;
		_mouseUpState[(uint)button] = true;
	}

	void InputDevice::Poll()
	{
		for (int i = 0; i < (uint)KeyCode::KEYBOARD_END; ++i)
		{
			if (_keyDownState[i])
			{
				_keyStayState[i] = true;
			}
			_keyUpState[i] = false;
		}

		for (int i = 0; i < (uint)MouseButton::MOUSE_END; ++i)
		{
			if (_mouseDownState[i])
			{
				_mouseStayState[i] = true;
			}
			_mouseUpState[i] = false;
		}
	}
}