#pragma once

#include "CotIInputListener.h"
#include "math/CotMath.h"
#include <queue>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	class COT_API MouseListener
		: public IInputListener
	{
	private:
		bool _mouseState[(uint)MouseButton::MOUSE_END];
		std::queue<MouseButton> _mouseDownQueue;
		std::queue<MouseButton> _mouseUpQueue;
		HWND _wnd;

	public:
		MouseListener();
		virtual ~MouseListener();

		Vec2 GetMousePosition();

		bool IsMouseDown(MouseButton code);
		bool IsMouseUp(MouseButton code);
		bool IsMouseStay(MouseButton code);

		void UpdateKeyDown(uint key) override;
		void UpdateKeyUp(uint key) override;

		void Clear() override;

	};
}