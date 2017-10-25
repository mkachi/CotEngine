#pragma once

#include "CotIInputListener.h"
#include <queue>

namespace Cot
{
	class COT_API KeyListener
		: public IInputListener
	{
	private:
		bool _keyState[(uint)KeyCode::KEYBOARD_END];
		bool _keyStayState[(uint)KeyCode::KEYBOARD_END];	
		std::queue<KeyCode> _keyDownQueue;
		std::queue<KeyCode> _keyUpQueue;

	public:
		KeyListener();
		virtual ~KeyListener();

		bool IsKeyDown(KeyCode code);
		bool IsKeyUp(KeyCode code);
		bool IsKeyStay(KeyCode code);

		void UpdateKeyDown(uint key) override;
		void UpdateKeyUp(uint key) override;

		void Clear() override;

	};
}