#pragma once

#include "base/CotRule.h"

namespace Cot
{
	class COT_API IRenderer
	{
		COT_INTERFACE(IRenderer);
	public:
		virtual void Draw() = 0;
	};
}