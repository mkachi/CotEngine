#pragma once

#include "CotTexture.h"

namespace Cot
{
	class COT_API TextureAtlas
		: public Asset
	{
	private:
		Texture*	_texture;
		Rect		_rect;
		
		bool Init(const string& key, Texture* texture, const Rect& rect);

	protected:
		TextureAtlas();

	public:
		virtual ~TextureAtlas();

		static TextureAtlas* Load(const string& key, Texture* texture, const Rect& rect);

		Texture* GetTexture() { return _texture; }
		Rect GetRect() { return _rect; }

		void Reload() override {}

	};
}