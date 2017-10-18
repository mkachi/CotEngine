#pragma once

#include "CotIRenderer.h"
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "math/CotColor.h"

namespace Cot
{
	class COT_API IGraphics
	{
		COT_INTERFACE(IGraphics);
	protected:
		std::vector<IRenderer*> _renderers;
		Color		_clearColor;

	public:
		virtual bool Init(HWND wnd) = 0;
		virtual void Destroy() = 0;

		virtual void AddRenderer(IRenderer* renderer) = 0;
		virtual void Render() = 0;

		void SetClearColor(const Color& color) { _clearColor = color; }
		Color GetClearColor() { return _clearColor; }

	};
}