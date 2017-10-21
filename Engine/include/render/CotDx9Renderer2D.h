#pragma once

#include "CotIRenderer.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9Renderer2D
		: public IRenderer
	{
public:
		Dx9Renderer2D();
		virtual ~Dx9Renderer2D();

		void Draw() override;

		static void Reset();
		static void Lost();

	};
}