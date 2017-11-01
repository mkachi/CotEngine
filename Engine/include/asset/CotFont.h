#pragma once

#include "CotAsset.h"
#include "math/CotMath.h"

namespace Cot
{
	class COT_API Font
		: public Asset
	{
	private:
		ID3DXFont*	_d3dFont;
		string		_fontName;
		string		_fontPath;
		int			_fontSize;

		bool Init(const string& filename, int fontSize);

	protected:
		Font();

	public:
		virtual ~Font();

		static Font* Load(const string& filename, int fontSize);

		ID3DXFont* GetData() { return _d3dFont; }
		string GetFontName() { return _fontName; }

		int GetFontSize() { return _fontSize; }
		string GetFontPath() { return _fontPath; }

		void Reload() override;

	};
}