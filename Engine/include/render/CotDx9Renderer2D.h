#pragma once

#include "CotIRenderer.h"
#include "math/CotMath.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9Renderer2D
		: public IRenderer
	{
	private:
		ID3DXSprite* _sprite;
		Rect	_screen;

	public:
		Dx9Renderer2D(int width, int height);
		virtual ~Dx9Renderer2D();

		void Draw() override;

	};
}