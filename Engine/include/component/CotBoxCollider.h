#pragma once

#include "CotICollider.h"

namespace Cot
{
	ComponentExt(BoxCollider, ICollider, COT_API)
	{
		COT_COMPONENT(BoxCollider);
	private:
		Size	_size;

	public:
		BoxCollider* Init(const Size& size = Size(300, 300));

		void Reset() override;
		void Update(Time& time) override;

		void SetSpriteSize();

		void SetRect(const Size& size);
		Rect GetRect() { return Rect(Vec2(GetOwner()->GetPosition().ToArray), _size); }

	};
}