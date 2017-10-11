#pragma once

#include "CotIRenderer.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9Renderer2D
		: public IRenderer
	{
	private:
		ID3DXSprite*		_sprite;
		IDirect3DDevice9*	_device;

	public:
		Dx9Renderer2D() = delete;
		Dx9Renderer2D(IDirect3DDevice9* device);
		virtual ~Dx9Renderer2D();

		void Draw() override;

	};
}