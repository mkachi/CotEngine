#pragma once

#include "CotKeyCode.h"

namespace Cot
{
	class COT_API IInputListener
	{
		COT_INTERFACE(IInputListener);
	public:
		virtual void UpdateKeyDown(uint key) = 0;
		virtual void UpdateKeyUp(uint key) = 0;

		virtual void Clear() = 0;

	};
}