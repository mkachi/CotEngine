#pragma once

#include "CotIComponent.h"
#include "math/CotMath.h"

namespace Cot
{
	Component(IRenderComponent, COT_API)
	{
		COT_COMPONENT(IRenderComponent);
	public:
		enum class Type
		{
			Sprite,
			Font,
		};
		
	protected:
		Type	_renderType;
		Vec2	_anchor;
		Color	_color;
		Rect	_rect;
		Size	_size;
		int		_depth;

	public:
		Type GetRenderType() { return _renderType; }

		void SetAnchor(const Vec2& anchor);
		Vec2 GetAnchor() { return _anchor; }

		void SetRect(const Rect& rect);
		Rect GetRect() { return _rect; }

		void SetSize(const Size& size);
		Size GetSize() { return _size; }

		void SetDepth(int depth);
		int GetDepth() { return _depth; }

		void SetColor(const Color& color);
		Color GetColor() { return _color; }

	};
}