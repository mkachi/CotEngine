#include "input/CotKeyListener.h"

namespace Cot
{
	KeyListener::KeyListener()
	{	}

	KeyListener::~KeyListener()
	{	}

	bool KeyListener::IsKeyDown(KeyCode code)
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

	bool KeyListener::IsKeyUp(KeyCode code)
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

	bool KeyListener::IsKeyStay(KeyCode code)
	{
		return _keyState[(uint)code];
	}

	void KeyListener::UpdateKeyDown(uint key)
	{
		KeyCode code = ToCotKeyCode(key);
		_keyState[(uint)code] = true;
		_keyDownQueue.push(code);
	}

	void KeyListener::UpdateKeyUp(uint key)
	{
		KeyCode code = ToCotKeyCode(key);
		_keyState[(uint)code] = false;
		_keyStayState[(uint)code] = false;
		_keyUpQueue.push(code);
	}

	void KeyListener::Clear()
	{
		CLEAR_QUEUE(_keyDownQueue);
		CLEAR_QUEUE(_keyUpQueue);
	}
}