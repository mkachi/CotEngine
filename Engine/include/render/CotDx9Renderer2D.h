#pragma once

#include "CotIRenderer.h"

namespace Cot
{
	class COT_API Dx9Renderer2D
		: public IRenderer
	{
	public:
		Dx9Renderer2D();
		virtual ~Dx9Renderer2D();

		void Draw() override;

	};
}