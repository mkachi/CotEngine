#pragma once

#include "CotIComponent.h"
#include "asset/CotTexture.h"

namespace Cot
{
	Component(SpriteRenderer, COT_API)
	{
		COT_COMPONENT(SpriteRenderer);
	private:
		Texture*	_texture;
		Vec2		_anchor;
		Color		_color;
		Rect		_rect;
		int			_depth;

	public:
		SpriteRenderer* Init(const string& filename);
		SpriteRenderer* Init(const string& filename, const Rect& rect);

		void Reset() override;
		void Update(Time& time) override;
		void OnDestroy() override;

		void SetTexture(const string& filename);
		Texture* GetTexture() { return _texture; }

		void SetAnchor(const Vec2& anchor);
		Vec2 GetAnchor() { return _anchor; }

		void SetColor(const Color& color);
		Color GetColor() { return _color; }

		void SetRect(const Rect& rect);
		Rect GetRect() { return _rect; }

		void SetDepth(int depth);
		int GetDepth() { return _depth; }

	};
}