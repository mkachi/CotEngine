#include "component/CotSpriteRenderer.h"
#include "render/CotRenderManager.h"

namespace Cot
{
	SpriteRenderer* SpriteRenderer::Init(const string& filename)
	{
		_texture = Texture::Load(filename);
		_rect = Rect(0, 0, _texture->GetWidth(), _texture->GetHeight());
		return this;
	}

	SpriteRenderer* SpriteRenderer::Init(const string& filename, const Rect& rect)
	{
		_texture = Texture::Load(filename);
		_rect = rect;
		return this;
	}

	void SpriteRenderer::Reset()
	{
		SafeRelease(_texture);
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		_depth = 0;
	}

	void SpriteRenderer::Update(Time& time)
	{
		RenderManager::GetInstance().Add(this);
	}

	void SpriteRenderer::OnDestroy()
	{
		_texture->Release();
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

	void SpriteRenderer::SetRect(const Rect& rect)
	{
		_rect = rect;
	}

	void SpriteRenderer::SetDepth(int depth)
	{
		_depth = depth;
	}
}