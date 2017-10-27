#include "render/CotDx9Device.h"
#include "render/CotDx9Renderer2D.h"
#include "math/CotGL2DX.h"

static IDirect3DDevice9* _device = nullptr;

namespace Cot
{
	Dx9Device::Dx9Device()
		: _d3d(nullptr)
	{	}

	Dx9Device::~Dx9Device()
	{	}

	bool Dx9Device::Init(HWND wnd)
	{
		_wnd = wnd;
		_clearColor = Color::Black;

		_d3d = Direct3DCreate9(D3D_SDK_VERSION);
		if (_d3d == NULL)
		{
			return false;
		}

		ZeroMemory(&_presentParam, sizeof(_presentParam));

		// Full Screen is FALSE
		_presentParam.Windowed = TRUE;
		_presentParam.hDeviceWindow = wnd;
		_presentParam.SwapEffect = D3DSWAPEFFECT_DISCARD;

		// Full Screen is D3DFMT_X8R8G8B8 window mode is D3DFMT_UNKNOWN
		_presentParam.BackBufferFormat = D3DFMT_UNKNOWN;

		// Full Screen BackBufferSize
		// _presentParam.BackBufferWidth = 800;
		// _presentParam.BackBufferHeight = 600;

		_presentParam.EnableAutoDepthStencil = TRUE;
		_presentParam.AutoDepthStencilFormat = D3DFMT_D24X8;
		_presentParam.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
		_presentParam.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;


		if (FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&_presentParam, &_device)))
		{
			return false;
		}

		_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		_device->SetRenderState(D3DRS_ZENABLE, false);
		_device->SetRenderState(D3DRS_LIGHTING, false);
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
		// Device lost
		//HRESULT result;
		//if (FAILED(result = _device->TestCooperativeLevel()))
		//{
		//	if (result == D3DERR_DEVICELOST)
		//	{
		//		return;
		//	}
		//
		//	if (result == D3DERR_DEVICENOTRESET)
		//	{
		//		_device->Reset(&_presentParam);
		//		return;
		//	}
		//}

		_device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, ToDxMath(_clearColor), 1.0f, 0);
		_device->BeginScene();

		for (auto& renderer : _renderers)
		{
			renderer->Draw();
		}
		_device->EndScene();
		_device->Present(NULL, NULL, NULL, NULL);
	}

	IDirect3DDevice9* Dx9Device::GetDevice()
	{
		return _device;
	}
}