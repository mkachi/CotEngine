#pragma once

#include "CotICollider.h"

namespace Cot
{
	ComponentExt(CircleCollider, ICollider, COT_API)
	{
		COT_COMPONENT(CircleCollider);
	private:
		float	_radius;
		Vec2	_offset;

	public:
		CircleCollider* Init(float radius = 0.0f);

		void Reset() override;
		void Update(Time& time) override;

		void SetOffset(const Vec2& offset);
		Vec2 GetOffset() { return _offset; }

		void SetRadius(float radius);
		Circle GetCircle();

	};
}