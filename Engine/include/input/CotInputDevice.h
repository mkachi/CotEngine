#pragma once

#include "CotKeyCode.h"
#include "math/CotVec2.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	class COT_API InputDevice final
	{
	private:
		HWND	_wnd;
		bool	_keyDownState[(uint)KeyCode::KEYBOARD_END];
		bool	_keyStayState[(uint)KeyCode::KEYBOARD_END];
		bool	_keyUpState[(uint)KeyCode::KEYBOARD_END];

		bool	_mouseDownState[(uint)MouseButton::MOUSE_END];
		bool	_mouseStayState[(uint)MouseButton::MOUSE_END];
		bool	_mouseUpState[(uint)MouseButton::MOUSE_END];

		float	_wheelValue;

	public:
		InputDevice(HWND wnd);
		~InputDevice();

		bool IsKeyDown(KeyCode code);
		bool IsKeyStay(KeyCode code);
		bool IsKeyUp(KeyCode code);

		void UpdateKeyDown(uint key);
		void UpdateKeyUp(uint key);

		bool IsMouseDown(MouseButton button);
		bool IsMouseStay(MouseButton button);
		bool IsMouseUp(MouseButton button);

		Vec2 GetMousePosition();
		float GetMouseWheel() { return _wheelValue; }

		void UpdateMouseDown(MouseButton button);
		void UpdateMouseUp(MouseButton button);
		HWND GetWindowHandle() { return _wnd; }

		void UpdateWheelValue(float wheel);

		void Poll();

	};
}