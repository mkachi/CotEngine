#pragma once

#include "CotKeyCode.h"
#include "math/CotVec2.h"

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <unordered_map>

namespace Cot
{
	class COT_API InputDevice final
	{
	private:
		std::unordered_map<KeyCode, uint> _swaper;
		IDirectInput8*			_directInput;
		IDirectInputDevice8*	_keyboard;
		IDirectInputDevice8*	_mouse;

		uchar			_keyState[256];
		DIMOUSESTATE	_mouseState;

		int		_screenWidth;
		int		_screenHeight;
		Vec2	_mousePosition;

		bool ReadKeyState();
		bool ReadMouseState();
		void ProcessInput();

	public:
		InputDevice();
		~InputDevice();

		bool Init(HINSTANCE instance, HWND wnd, int width, int height);
		void Destroy();
		void Update();

		uchar* GetKeyState() { return _keyState; }
		Vec2 GetMousePosition() { return _mousePosition; }
		DIMOUSESTATE GetMouseState() { return _mouseState; }

		void CreateKeyCodeTable();
		uint DikToKeyCode(KeyCode code);

	};
}