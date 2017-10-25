#pragma once

#include "CotIInputListener.h"
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	class COT_API InputManager final
	{
		COT_SINGLETON_H(InputManager);
	private:
		std::vector<IInputListener*> _keyListeners;
		std::vector<IInputListener*> _mouseListeners;
		HWND	_wnd;

	public:
		void SetHandle(HWND handle);
		HWND GetHandle() { return _wnd; }

		void AddKeyListener(IInputListener* keyListener);
		void AddMouseListener(IInputListener* mouseListener);

		void RemoveKeyListener(IInputListener* keyListener);
		void RemoveMouseListener(IInputListener* mouseListener);

		void UpdateKeyDown(uint key);
		void UpdateKeyUp(uint key);

		void UpdateMouseDown(uint key);
		void UpdateMouseUp(uint key);

		void Clear();

	};
}