#pragma once

#include "CotIRenderComponent.h"
#include "asset/CotFont.h"

namespace Cot
{
	ComponentExt(FontRenderer, IRenderComponent, COT_API)
	{
		COT_COMPONENT(FontRenderer);
	private:
		Font*	_font;
		string	_text;

	public:
		FontRenderer* Init(const string& font, const string& text, int fontSize);

		void Reset() override;
		void Update(Time& time) override;
		void OnDestroy() override;

		void SetFont(Font* font);
		void SetFont(const string& font, int fontSize);
		Font* GetFont() { return _font; }

		void SetFontSize(int fontSize);
		int GetFontSize() { return _font->GetFontSize(); }

		void SetText(const string& text);
		string GetText() { return _text; }

	};
}