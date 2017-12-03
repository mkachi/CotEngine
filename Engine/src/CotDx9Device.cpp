#include "render/CotDx9Device.h"
#include "render/CotDx9Renderer2D.h"
#include "math/CotGL2DX.h"
#include "asset/CotAssetManager.h"

static IDirect3DDevice9* _device = nullptr;

namespace Cot
{
	Dx9Device::Dx9Device()
		: _d3d(nullptr)
	{	}

	Dx9Device::~Dx9Device()
	{	}

	bool Dx9Device::Init(HWND wnd, uint width, uint height, bool fullScreen)
	{
		_wnd = wnd;
		_fullScreen = fullScreen;
		_width = width;
		_height = height;
		_clearColor = Color::Black;

		_d3d = Direct3DCreate9(D3D_SDK_VERSION);
		if (_d3d == NULL)
		{
			return false;
		}

		// Present Param
		InitPresentParam();

		if (fullScreen)
		{
			if (CheckAdapterCompatible())
			{
				_presentParam.FullScreen_RefreshRateInHz = _displayMode.RefreshRate;
			}
			else
			{
				COT_ASSERT(true, "Graphics device does not support specified resolution or format");
			}
		}

		D3DCAPS9 caps;
		caps.RasterCaps = D3DPRASTERCAPS_SCISSORTEST;

		DWORD processingType;
		_d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
		if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 ||
			caps.VertexShaderVersion < D3DVS_VERSION(1, 1))
		{
			processingType = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}
		else
		{
			processingType = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		}

		if (FAILED(_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _wnd,
			processingType,
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

	bool Dx9Device::CheckAdapterCompatible()
	{
		uint modes = _d3d->GetAdapterModeCount(D3DADAPTER_DEFAULT, _presentParam.BackBufferFormat);
		for (uint i = 0; i < modes; ++i)
		{
			_d3d->EnumAdapterModes(D3DADAPTER_DEFAULT, _presentParam.BackBufferFormat, i, &_displayMode);

			if (_displayMode.Height == _presentParam.BackBufferHeight &&
				_displayMode.Width == _presentParam.BackBufferWidth &&
				_displayMode.RefreshRate >= _presentParam.FullScreen_RefreshRateInHz)
			{
				return true;
			}
		}
		return false;
	}

	void Dx9Device::InitPresentParam()
	{
		ZeroMemory(&_presentParam, sizeof(_presentParam));

		// Full Screen is FALSE
		_presentParam.Windowed = (!_fullScreen);
		_presentParam.hDeviceWindow = _wnd;
		_presentParam.SwapEffect = D3DSWAPEFFECT_DISCARD;

		if (_fullScreen)
		{
			_presentParam.BackBufferFormat = D3DFMT_X8R8G8B8;
		}
		else
		{
			_presentParam.BackBufferFormat = D3DFMT_UNKNOWN;
		}

		_presentParam.BackBufferWidth = _width;
		_presentParam.BackBufferHeight = _height;

		_presentParam.EnableAutoDepthStencil = TRUE;
		_presentParam.AutoDepthStencilFormat = D3DFMT_D24X8;
		_presentParam.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
		_presentParam.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
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
		_device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, ToDxMath(_clearColor), 1.0f, 0);
		_device->BeginScene();

		for (auto& renderer : _renderers)
		{
			renderer->Draw();
		}
		_device->EndScene();
		_device->Present(NULL, NULL, NULL, NULL);

		// Device lost
		HRESULT result;
		if (FAILED(result = _device->TestCooperativeLevel()))
		{
			if (result == D3DERR_DEVICELOST)
			{
				Sleep(100);
				return;
			}

			if (result == D3DERR_DEVICENOTRESET)
			{
				Reset();
			}
		}
	}

	void Dx9Device::SetFullScreen(bool fullScreen)
	{
		_fullScreen = fullScreen;
		if (fullScreen)
		{
			SetWindowLong(_wnd, GWL_STYLE, WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP);
		}
		else
		{
			SetWindowLong(_wnd, GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX);
			SetWindowPos(_wnd, HWND_TOP, 0, 0, _width, _height, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
		}
		Reset();
	}

	void Dx9Device::Reset()
	{
		InitPresentParam();

		for (auto& renderer : _renderers)
		{
			renderer->Lost();
		}

		_device->Reset(&_presentParam);
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

		for (auto& renderer : _renderers)
		{
			renderer->Reset();
		}

		AssetManager::GetInstance().ReloadAll();
	}

	IDirect3DDevice9* Dx9Device::GetDevice()
	{
		return _device;
	}
}