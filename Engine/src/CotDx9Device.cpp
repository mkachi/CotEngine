#include "render/CotDx9Device.h"

namespace Cot
{
	Dx9Device::Dx9Device()
		: _d3d(nullptr)
		, _device(nullptr)
	{	}

	Dx9Device::~Dx9Device()
	{	}

	bool Dx9Device::Init(HWND wnd)
	{
		_d3d = Direct3DCreate9(D3D_SDK_VERSION);
		if (_d3d == NULL)
		{
			return false;
		}

		D3DPRESENT_PARAMETERS presentParam;
		ZeroMemory(&presentParam, sizeof(presentParam));

		presentParam.Windowed = TRUE;
		presentParam.SwapEffect = D3DSWAPEFFECT_DISCARD;
		presentParam.BackBufferFormat = D3DFMT_UNKNOWN;
		presentParam.EnableAutoDepthStencil = TRUE;
		presentParam.AutoDepthStencilFormat = D3DFMT_D24X8;
		presentParam.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
		presentParam.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		if (FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&presentParam, &_device)))
		{
			return false;
		}

		_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		_device->SetRenderState(D3DRS_ZENABLE, true);
		_device->SetRenderState(D3DRS_LIGHTING, true);
		_device->SetRenderState(D3DRS_AMBIENT, 0x00202020);
		_device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
		_device->SetRenderState(D3DRS_SPECULARENABLE, true);

		_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

		_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
		_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

		_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		return true;
	}

	void Dx9Device::AddRenderer(IRenderer* renderer)
	{
		if (renderer != nullptr)
		{
			_renderers.push_back(renderer);
		}
	}

	void Dx9Device::Destroy()
	{
		for (auto& renderer : _renderers)
		{
			SafeDelete(renderer);
		}

		SafeRelease(_d3d);
		SafeRelease(_device);
	}

	void Dx9Device::Render()
	{
		_device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		_device->BeginScene();
		for (auto& renderer : _renderers)
		{
			renderer->Draw();
		}
		_device->EndScene();
		_device->Present(NULL, NULL, NULL, NULL);
	}
}