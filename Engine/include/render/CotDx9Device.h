#pragma once

#include "render/CotIGraphics.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Dx9Device
		: public IGraphics
	{
	private:
		IDirect3D9*			_d3d;
		IDirect3DDevice9*	_device;

	public:
		Dx9Device();
		virtual ~Dx9Device();

		bool Init(HWND wnd) override;
		void AddRenderer(IRenderer* renderer) override;
		void Destroy() override;
		void Render() override;

		IDirect3DDevice9* GetDevice() { return _device; }

	};
}