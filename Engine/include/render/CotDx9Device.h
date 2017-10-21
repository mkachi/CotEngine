#pragma once

#include "render/CotIGraphics.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9Device
		: public IGraphics
	{
	private:
		IDirect3D9*		_d3d;
		HWND			_wnd;

	public:
		Dx9Device();
		virtual ~Dx9Device();

		bool Init(HWND wnd, uint width, uint height, bool fullScreen) override;
		
		void SetWinSize(const Size& size) override;
		
		void SetFullScreen(bool value) override;
		void AddRenderer(IRenderer* renderer) override;
		void Destroy() override;
		void Render() override;

		static IDirect3DDevice9* GetDevice();

	};
}