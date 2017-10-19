#pragma once

#include "CotIRenderer.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9DebugRenderer
		: public IRenderer
	{
	private:

	public:
		Dx9DebugRenderer();
		virtual ~Dx9DebugRenderer();

		void Draw() override;

	};
}