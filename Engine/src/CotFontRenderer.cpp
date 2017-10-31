#include "component/CotFontRenderer.h"
#include "render/CotRenderManager.h"

namespace Cot
{
	FontRenderer* FontRenderer::Init(const string& font, const string& text, int fontSize)
	{
		Reset();
		_font = Font::Load(font, fontSize);
		_text = text;
		_font->Retain();
		_rect.SetRect(0, 0, 0, 0);
		return this;
	}

	void FontRenderer::Reset()
	{
		_renderType = IRenderComponent::Type::Font;
		_text = "";
		SafeRelease(_font);
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		_depth = 0;
	}

	void FontRenderer::Update(Time& time)
	{
		RenderManager::GetInstance().Add(this);
	}

	void FontRenderer::OnDestroy()
	{
		SafeRelease(_font);
	}

	void FontRenderer::SetFont(Font* font)
	{
		SafeRelease(_font);
		_font = font;
		_font->Retain();
	}

	void FontRenderer::SetFont(const string& font, int fontSize)
	{
		SafeRelease(_font);
		_font = Font::Load(font, fontSize);
		_font->Retain();
	}

	void FontRenderer::SetText(const string& text)
	{
		_text = text;
	}

	void FontRenderer::SetFontSize(int fontSize)
	{
		string path = _font->GetFontPath();
		SafeRelease(_font);
		_font = Font::Load(path, fontSize);
		_font->Release();
	}
}