#pragma once

#include "CotIRenderer.h"
#include <vector>
#include <Windows.h>

namespace Cot
{
	class COT_API IGraphics
	{
		COT_INTERFACE(IGraphics);
	protected:
		std::vector<IRenderer*> _renderers;

	public:
		virtual bool Init(HWND wnd) = 0;
		virtual void Destroy() = 0;

		virtual void AddRenderer(IRenderer* renderer) = 0;
		virtual void Render() = 0;
	};
}