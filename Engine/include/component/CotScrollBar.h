#pragma once

#include "CotSpriteRenderer.h"
#include "base/CotScene.h"

namespace Cot
{
	ComponentExt(ScrollBar, SpriteRenderer, COT_API)
	{
		COT_COMPONENT(ScrollBar);
	private:
		Entity* _button;
		bool	_buttonDown;
		float	_beginY;
		float	_endY;

		float	_value;
		float	_minValue;
		float	_maxValue;

	public:
		ScrollBar* Init(const string& background, Entity* button);
		
		void Reset() override;
		void Update(Time& time) override;
		void OnDestroy() override;

		void SetValue(float value);
		float GetValue() { return _value; }

	};
}