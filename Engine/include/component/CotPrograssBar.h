#pragma once

#include "CotSpriteRenderer.h"

namespace Cot
{
	Component(PrograssBar, COT_API)
	{
		COT_COMPONENT(PrograssBar);
	private:
		SpriteRenderer* _spriteRenderer;
		float _value;
		float _x;

	public:
		void Reset() override;
		void Awake() override;

		void SetValue(float value);
		float GetValue() { return _value; }
		
	};
}