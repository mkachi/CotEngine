#pragma once

#include "base/CotRule.h"

namespace Cot
{
	class COT_API IRenderer
	{
		COT_INTERFACE(IRenderer);

		virtual void Draw() = 0;
	};
}