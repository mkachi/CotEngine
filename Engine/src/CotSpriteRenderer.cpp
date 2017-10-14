#include "component/CotSpriteRenderer.h"
#include "render/CotRenderManager.h"

namespace Cot
{
	SpriteRenderer* SpriteRenderer::Init(const string& filename)
	{
		Reset();
		_texture = Texture::Load(filename);
		return this;
	}

	SpriteRenderer* SpriteRenderer::InitWithAtlas(const string& atlas, const Rect& rect)
	{
		Reset();
		_texture = Texture::Load(atlas);
		_rect = rect;
		_atlas = true;
		return this;
	}

	void SpriteRenderer::Reset()
	{
		SafeRelease(_texture);
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		_depth = false;
		_atlas = false;
	}

	void SpriteRenderer::Update(Time& time)
	{
		RenderManager::GetInstance().Add(this);
	}

	void SpriteRenderer::SetTexture(const string& filename)
	{
		SafeRelease(_texture);
		_texture = Texture::Load(filename);
	}

	void SpriteRenderer::SetAnchor(const Vec2& anchor)
	{
		_anchor = anchor;
	}

	void SpriteRenderer::SetColor(const Color& color)
	{
		_color = color;
	}

	void SpriteRenderer::SetAtlasRect(const Rect& rect)
	{
		_rect = rect;
	}

	void SpriteRenderer::SetDepth(int depth)
	{
		_depth = depth;
	}
}