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
		bool		_atlas;

	public:
		SpriteRenderer* Init(const string& filename);
		void Update(Time& time) override;

		Texture* GetTexture() { return _texture; }
		Vec2 GetAnchor() { return _anchor; }
		Color GetColor() { return _color; }
		Rect GetAtlasRect() { return _rect; }
		int GetDepth() { return _depth; }
		bool IsAtlasSprite() { return _atlas; }

	};
}