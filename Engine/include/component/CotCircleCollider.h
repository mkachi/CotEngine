#pragma once

#include "CotICollider.h"

namespace Cot
{
	ComponentExt(CircleCollider, ICollider, COT_API)
	{
		COT_COMPONENT(CircleCollider);
	private:
		float	_radius;

	public:
		CircleCollider* Init(float radius = 0.0f);

		void Reset() override;
		void Update(Time& time) override;

		void SetRadius(float radius);
		Circle GetCircle() { return Circle(_radius, Vec2(GetOwner()->GetPosition().ToArray)); }

	};
}