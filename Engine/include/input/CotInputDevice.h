#pragma once

#include "base/CotRule.h"
#include "math/CotVec2.h"
#include "CotKeyCode.h"
#include <queue>
#include <unordered_map>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	class COT_API InputDevice final
	{
	private:
		bool _keyState[(uint)KeyCode::KEYBOARD_END];
		bool _keyStayState[(uint)KeyCode::KEYBOARD_END];
		std::queue<KeyCode> _keyDownQueue;
		std::queue<KeyCode> _keyUpQueue;

		bool _mouseState[(uint)MouseButton::MOUSE_END];
		std::queue<MouseButton> _mouseDownQueue;
		std::queue<MouseButton> _mouseUpQueue;

		std::unordered_map<uchar, KeyCode>		_keySwaper;
		HWND _wnd;

		KeyCode ToKeyCode(uint key) { return _keySwaper[key]; }

	public:
		InputDevice() = delete;
		InputDevice(HWND wnd);
		~InputDevice();

		void CreateKeyCodeTable();
		Vec2 GetMousePosition();

		bool IsKeyDown(KeyCode code);
		bool IsKeyUp(KeyCode code);
		bool IsKeyStay(KeyCode code);

		bool IsMouseDown(MouseButton code);
		bool IsMouseUp(MouseButton code);
		bool IsMouseStay(MouseButton code);

		void UpdateKeyDown(uint key);
		void UpdateKeyUp(uint key);

		void UpdateMouseDown(MouseButton button);
		void UpdateMouseUp(MouseButton button);
		void Clear();

	};
}