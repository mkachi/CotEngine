#pragma once

#include "CotIComponent.h"

namespace Cot
{
	Component(SpriteRenderer, COT_API)
	{
		COT_COMPONENT(SpriteRenderer);
	private:

	public:
		SpriteRenderer* Init(const string& filename);

	};
}