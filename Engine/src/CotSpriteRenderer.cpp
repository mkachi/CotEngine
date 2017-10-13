#include "component/CotSpriteRenderer.h"
#include "render/CotRenderManager.h"

namespace Cot
{
	SpriteRenderer* SpriteRenderer::Init(const string& filename)
	{
		_texture = Texture::Load(filename);
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		return this;
	}

	void SpriteRenderer::Update(Time& time)
	{
		RenderManager::GetInstance().Add(this);
	}
}