#pragma once

#include "CotIRenderer.h"
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "math/CotMath.h"

namespace Cot
{
	class COT_API IGraphics
	{
		COT_INTERFACE(IGraphics);
	protected:
		std::vector<IRenderer*> _renderers;
		Size		_winSize;
		Color		_clearColor;
		bool		_fullScreen;

	public:
		virtual bool Init(HWND wnd, uint width, uint height, bool fullScreen) = 0;
		virtual void Destroy() = 0;

		virtual void SetFullScreen(bool value) = 0;
		bool IsFullScreen() { return _fullScreen; }

		virtual void AddRenderer(IRenderer* renderer) = 0;
		virtual void Render() = 0;

		void SetClearColor(const Color& color) { _clearColor = color; }
		Color GetClearColor() { return _clearColor; }

		virtual void SetWinSize(const Size& size) = 0;
		Size GetWinSize() { return _winSize; }

	};
}