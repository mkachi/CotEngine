#pragma once

#include "CotICollider.h"

namespace Cot
{
	ComponentExt(BoxCollider, ICollider, COT_API)
	{
		COT_COMPONENT(BoxCollider);
	private:
		Size	_size;
		Vec2	_offset;

	public:
		BoxCollider* Init(const Size& size = Size(300, 300));

		void Reset() override;
		void Update(Time& time) override;

		void SetSpriteSize();

		void SetOffset(const Vec2& offset);
		Vec2 GetOffset() { return _offset; }

		void SetRect(const Size& size);
		Rect GetRect();

	};
}