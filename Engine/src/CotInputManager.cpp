#include "input/CotInputManager.h"

namespace Cot
{
	COT_SINGLETON_CPP(InputManager);

	void InputManager::SetHandle(HWND handle)
	{
		_wnd = handle;
	}

	void InputManager::AddKeyListener(IInputListener* keyListener)
	{
		_keyListeners.push_back(keyListener);
	}

	void InputManager::AddMouseListener(IInputListener* mouseListener)
	{
		_mouseListeners.push_back(mouseListener);
	}

	void InputManager::RemoveKeyListener(IInputListener* keyListener)
	{
		_keyListeners.erase(std::find(_keyListeners.begin(), _keyListeners.end(), keyListener));
	}

	void InputManager::RemoveMouseListener(IInputListener* mouseListener)
	{
		_mouseListeners.erase(std::find(_mouseListeners.begin(), _mouseListeners.end(), mouseListener));
	}

	void InputManager::UpdateKeyDown(uint key)
	{
		for (int i = 0; i < _keyListeners.size(); ++i)
		{
			_keyListeners[i]->UpdateKeyDown(key);
		}
	}

	void InputManager::UpdateKeyUp(uint key)
	{
		for (int i = 0; i < _keyListeners.size(); ++i)
		{
			_keyListeners[i]->UpdateKeyUp(key);
		}
	}

	void InputManager::UpdateMouseDown(uint key)
	{
		for (int i = 0; i < _mouseListeners.size(); ++i)
		{
			_mouseListeners[i]->UpdateKeyDown(key);
		}
	}

	void InputManager::UpdateMouseUp(uint key)
	{
		for (int i = 0; i < _mouseListeners.size(); ++i)
		{
			_mouseListeners[i]->UpdateKeyUp(key);
		}
	}

	void InputManager::Clear()
	{
		for (int i = 0; i < _keyListeners.size(); ++i)
		{
			_keyListeners[i]->Clear();
		}

		for (int i = 0; i < _mouseListeners.size(); ++i)
		{
			_mouseListeners[i]->Clear();
		}
	}
}