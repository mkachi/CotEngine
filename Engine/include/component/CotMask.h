#pragma once

#include "CotIComponent.h"
#include "math/CotMath.h"

namespace Cot
{
	class SpriteRenderer;
	Component(Mask, COT_API)
	{
		COT_COMPONENT(Mask);
	private:
		Rect			_maskRect;
		SpriteRenderer* _renderer;

	public:
		Mask* Init(SpriteRenderer* renderer);
		Rect GetRect() { return _maskRect; }

		void Start() override;

	};
}