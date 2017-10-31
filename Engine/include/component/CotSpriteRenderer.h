#pragma once

#include "CotIRenderComponent.h"
#include "asset/CotTexture.h"

namespace Cot
{
	ComponentExt(SpriteRenderer, IRenderComponent, COT_API)
	{
		COT_COMPONENT(SpriteRenderer);
	private:
		Texture*	_texture;

	public:
		SpriteRenderer* Init(const string& filename);
		SpriteRenderer* Init(const string& caif, const string& key);

		void Reset() override;
		void Update(Time& time) override;
		void OnDestroy() override;

		void SetTexture(Texture* texture);
		void SetTexture(const string& filename);
		void SetTexture(const string& caif, const string& key);
		Texture* GetTexture() { return _texture; }

	};
}