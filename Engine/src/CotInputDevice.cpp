#include "input/CotInputDevice.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define CLEAR_QUEUE(_queue_) \
	for(int i = 0; i < _queue_.size(); ++i) \
	{ \
		_queue_.pop(); \
	}

namespace Cot
{
	InputDevice::InputDevice(HWND wnd)
		: _wnd(wnd)
	{	}

	InputDevice::~InputDevice()
	{	}

	Vec2 InputDevice::GetMousePosition()
	{
		POINT point;
		GetCursorPos(&point);
		ScreenToClient(_wnd, &point);
		return Vec2(point.x, point.y);
	}

	bool InputDevice::IsKeyDown(KeyCode code)
	{
		if (_keyDownQueue.empty() || _keyStayState[(uint)code])
		{
			return false;
		}

		KeyCode temp = _keyDownQueue.front();
		if (temp == code)
		{
			_keyStayState[(uint)code] = true;
			_keyDownQueue.pop();
			return true;
		}
		return false;
	}

	bool InputDevice::IsKeyUp(KeyCode code)
	{
		if (_keyUpQueue.empty())
		{
			return false;
		}

		KeyCode temp = _keyUpQueue.front();
		if (temp == code)
		{
			_keyUpQueue.pop();
			return true;
		}
		return false;
	}

	bool InputDevice::IsKeyStay(KeyCode code)
	{
		return _keyState[(uint)code];
	}

	bool InputDevice::IsMouseDown(MouseButton code)
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

	bool InputDevice::IsMouseUp(MouseButton code)
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

	bool InputDevice::IsMouseStay(MouseButton code)
	{
		return _mouseState[(uint)code];
	}

	void InputDevice::UpdateKeyDown(uint key)
	{
		KeyCode code = ToKeyCode(key);
		_keyState[(uint)code] = true;
		_keyDownQueue.push(code);
	}

	void InputDevice::UpdateKeyUp(uint key)
	{
		KeyCode code = ToKeyCode(key);
		_keyState[(uint)code] = false;
		_keyStayState[(uint)code] = false;
		_keyUpQueue.push(code);
	}

	void InputDevice::UpdateMouseDown(MouseButton button)
	{
		_mouseState[(uint)button] = true;
		_mouseDownQueue.push(button);
	}

	void InputDevice::UpdateMouseUp(MouseButton button)
	{
		_mouseState[(uint)button] = false;
		_mouseUpQueue.push(button);
	}

	void InputDevice::Clear()
	{
		CLEAR_QUEUE(_keyDownQueue);
		CLEAR_QUEUE(_keyUpQueue);
		CLEAR_QUEUE(_mouseDownQueue);
		CLEAR_QUEUE(_mouseUpQueue);
	}

	void InputDevice::CreateKeyCodeTable()
	{
		_keySwaper = {
			{ VK_ESCAPE			, KeyCode::Esc			 , },
			{ VK_F1				, KeyCode::F1			 , },
			{ VK_F2				, KeyCode::F2			 , },
			{ VK_F3				, KeyCode::F3			 , },
			{ VK_F4				, KeyCode::F4			 , },
			{ VK_F5				, KeyCode::F5			 , },
			{ VK_F6				, KeyCode::F6			 , },
			{ VK_F7				, KeyCode::F7			 , },
			{ VK_F8				, KeyCode::F8			 , },
			{ VK_F9				, KeyCode::F9			 , },
			{ VK_F10			, KeyCode::F10			 , },
			{ VK_F11			, KeyCode::F11			 , },
			{ VK_F12			, KeyCode::F12			 , },
			{ VK_SNAPSHOT		, KeyCode::PrintScreen	 , },
			{ VK_SCROLL			, KeyCode::Scroll		 , },
			{ VK_PAUSE			, KeyCode::Pause		 , },
			{ '0'				, KeyCode::_0			 , },
			{ '1'				, KeyCode::_1			 , },
			{ '2'				, KeyCode::_2			 , },
			{ '3'				, KeyCode::_3			 , },
			{ '4'				, KeyCode::_4			 , },
			{ '5'				, KeyCode::_5			 , },
			{ '6'				, KeyCode::_6			 , },
			{ '7'				, KeyCode::_7			 , },
			{ '8'				, KeyCode::_8			 , },
			{ '9'				, KeyCode::_9			 , },
			{ VK_OEM_MINUS		, KeyCode::Minus		 , },
			{ VK_OEM_PLUS		, KeyCode::Equals		 , },
			{ 0x08	/* ? */		, KeyCode::BackSpace	 , },
			{ VK_TAB			, KeyCode::Tab			 , },
			{ 'Q'				, KeyCode::Q			 , },
			{ 'W'				, KeyCode::W			 , },
			{ 'E'				, KeyCode::E			 , },
			{ 'R'				, KeyCode::R			 , },
			{ 'T'				, KeyCode::T			 , },
			{ 'Y'				, KeyCode::Y			 , },
			{ 'U'				, KeyCode::U			 , },
			{ 'I'				, KeyCode::I			 , },
			{ 'O'				, KeyCode::O			 , },
			{ 'P'				, KeyCode::P			 , },
			{ VK_OEM_4			, KeyCode::LBracket		 , },
			{ VK_OEM_6			, KeyCode::RBracket	 	 , },
			{ VK_RETURN			, KeyCode::Enter		 , },
			{ VK_LCONTROL		, KeyCode::LCtrl		 , },
			{ VK_RCONTROL		, KeyCode::RCtrl		 , },
			{ 'A'				, KeyCode::A			 , },
			{ 'S'				, KeyCode::S			 , },
			{ 'D'				, KeyCode::D			 , },
			{ 'F'				, KeyCode::F			 , },
			{ 'G'				, KeyCode::G			 , },
			{ 'H'				, KeyCode::H			 , },
			{ 'J'				, KeyCode::J			 , },
			{ 'K'				, KeyCode::K			 , },
			{ 'L'				, KeyCode::L			 , },
			{ VK_OEM_1			, KeyCode::Semicolon	 , },
			{ VK_OEM_7			, KeyCode::Apostrophe 	 , },
			{ VK_OEM_3			, KeyCode::Grave		 , },
			{ VK_LSHIFT			, KeyCode::LShift		 , },
			{ VK_OEM_102		, KeyCode::BackSlash	 , },
			{ 'Z'				, KeyCode::Z			 , },
			{ 'X'				, KeyCode::X			 , },
			{ 'C'				, KeyCode::C			 , },
			{ 'V'				, KeyCode::V			 , },
			{ 'B'				, KeyCode::B			 , },
			{ 'N'				, KeyCode::N			 , },
			{ 'M'				, KeyCode::M			 , },
			{ VK_OEM_COMMA		, KeyCode::Comma		 , },
			{ VK_OEM_PERIOD		, KeyCode::Period		 , },
			{ VK_OEM_2			, KeyCode::Slash		 , },
			{ VK_RSHIFT			, KeyCode::RShift		 , },

			// Alt										
			{ VK_MENU			, KeyCode::LAlt			 , },
			{ VK_MENU			, KeyCode::RAlt			 , },

			{ VK_LWIN			, KeyCode::LWin			 , },
			{ VK_RWIN			, KeyCode::RWin			 , },
			{ VK_CAPITAL		, KeyCode::CapsLock		 , },
			{ VK_UP				, KeyCode::Up			 , },
			{ VK_DOWN			, KeyCode::Down			 , },
			{ VK_LEFT			, KeyCode::Left			 , },
			{ VK_RIGHT			, KeyCode::Right		 , },
			{ VK_PRIOR			, KeyCode::PgUp			 , },
			{ VK_NEXT			, KeyCode::PgDown		 , },
			{ VK_INSERT			, KeyCode::Insert		 , },
			{ VK_HOME			, KeyCode::Home			 , },
			{ VK_DELETE			, KeyCode::Delete		 , },
			{ VK_END			, KeyCode::End			 , },
			{ VK_NUMLOCK		, KeyCode::Num_Lock		 , },
			{ VK_DIVIDE			, KeyCode::Num_Slash	 , },
			{ VK_MULTIPLY		, KeyCode::Num_Multiply  , },
			{ VK_SUBTRACT		, KeyCode::Num_Minus	 , },
			{ VK_ADD			, KeyCode::Num_Plus		 , },
			{ VK_RETURN			, KeyCode::Num_Enter	 , },
			{ VK_DECIMAL		, KeyCode::Num_Decimal	 , },
			{ VK_NUMPAD0		, KeyCode::Num_0		 , },
			{ VK_NUMPAD1		, KeyCode::Num_1		 , },
			{ VK_NUMPAD2		, KeyCode::Num_2		 , },
			{ VK_NUMPAD3		, KeyCode::Num_3		 , },
			{ VK_NUMPAD4		, KeyCode::Num_4		 , },
			{ VK_NUMPAD5		, KeyCode::Num_5		 , },
			{ VK_NUMPAD6		, KeyCode::Num_6		 , },
			{ VK_NUMPAD7		, KeyCode::Num_7		 , },
			{ VK_NUMPAD8		, KeyCode::Num_8		 , },
			{ VK_NUMPAD9		, KeyCode::Num_9		 , },
			{ VK_SPACE			, KeyCode::SpaceBar		 , },
		};
	}
}