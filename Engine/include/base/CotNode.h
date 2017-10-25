#pragma once

#include "base/CotRule.h"
#include "input/CotKeyListener.h"
#include "input/CotMouseListener.h"

namespace Cot
{
	class COT_API Node
	{
	private:
		KeyListener*	_keyListener;
		MouseListener*	_mouseListener;

	protected:
		Node();

	public:
		virtual ~Node();

		void CreateKeyListener();
		void CreateMouseListener();

		void DestroyListeners();

		KeyListener* GetKeyListener() { return _keyListener; }
		MouseListener* GetMouseListener() { return _mouseListener; }

	};
}