#include "base/CotApplication.h"
#include "base/CotSceneManager.h"
#include "render/CotDx9Device.h"
#include "render/CotDx9Renderer2D.h"
#include "render/CotRenderManager.h"
#include "asset/CotAudioClip.h"
#include "asset/CotAssetManager.h"

namespace Cot
{
	Application::Application()
		: _graphics(nullptr)
		, _inputDevice(nullptr)
	{	}

	Application::~Application()
	{	}

	LRESULT Application::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_KEYUP:			UpdateKeyUp(wParam);		return 0;
		case WM_KEYDOWN:		UpdateKeyDown(wParam);		return 0;

		case WM_LBUTTONDOWN:	UpdateMouseDown(MouseButton::LButton);	return 0;
		case WM_LBUTTONUP:		UpdateMouseUp(MouseButton::LButton);	return 0;

		case WM_RBUTTONDOWN:	UpdateMouseDown(MouseButton::RButton);	return 0;
		case WM_RBUTTONUP:		UpdateMouseUp(MouseButton::RButton);	return 0;

		case WM_MBUTTONDOWN:	UpdateMouseDown(MouseButton::MButton);	return 0;;
		case WM_MBUTTONUP:		UpdateMouseUp(MouseButton::MButton);	return 0;;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	bool Application::InitGraphcis()
	{
		_graphics = new Dx9Device();
		if (!_graphics->Init(_wnd))
		{
			return false;
		}
		_graphics->AddRenderer(new Dx9Renderer2D());

		return true;
	}

	bool Application::Init(HINSTANCE instance, const string& title, int width, int height, bool fullScreen)
	{
		_title = ToWString(title);
		_instance = instance;

		WNDCLASSEX wcx;
		ZeroMemory(&wcx, sizeof(WNDCLASSEX));

		wcx.cbSize = sizeof(wcx);
		wcx.cbClsExtra = 0;
		wcx.cbWndExtra = 0;
		wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wcx.hCursor = LoadCursor(_instance, IDC_ARROW);
		wcx.hIcon = LoadIcon(_instance, IDI_APPLICATION);
		wcx.hInstance = _instance;
		wcx.lpfnWndProc = MsgProc;
		wcx.lpszClassName = _title.c_str();
		wcx.lpszMenuName = NULL;
		wcx.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wcx))
		{
			MessageBox(NULL, L"Cannot register window class.", L"Error", MB_OK);
			return false;
		}

		_wnd = CreateWindowEx(
			NULL, _title.c_str(), _title.c_str(),
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX, 0, 0, 
			width, height, NULL, NULL, _instance, NULL);

		if (!_wnd)
		{
			MessageBox(NULL, L"Cannot create window.", L"Error", MB_OK);
			return false;
		}

		if (!InitGraphcis())
		{
			MessageBox(NULL, L"Cannot create graphics device.", L"Error", MB_OK);
			return false;
		}
		SceneManager::GetInstance().SetGraphicsDevice(_graphics);

		ShowWindow(_wnd, SW_SHOWDEFAULT);
		UpdateWindow(_wnd);

		_inputDevice = new InputDevice(_wnd);
		if (_inputDevice == nullptr)
		{
			MessageBox(NULL, L"Cannot create input device.", L"Error", MB_OK);
			return false;
		}
		_inputDevice->CreateKeyCodeTable();
		RegisteInputDevice(_inputDevice);

		return true;
	}

	void Application::RunWithScene(Scene* scene)
	{
		SceneManager& sceneManager = SceneManager::GetInstance();
		sceneManager.LoadScene(scene);

		Time time;
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				time.Tick();
				sceneManager.Update(time);
				InputClear();
				_graphics->Render();
			}
		}
	}

	void Application::Destroy()
	{
		DestroyAllDecoder();

		RenderManager::Destroy();
		AssetManager::GetInstance().DestroyAllAssets();
		AssetManager::Destroy();

		SafeDelete(_inputDevice);

		SceneManager::GetInstance().DestroyAllScene();
		SceneManager::Destroy();

		SafeDestroy(_graphics);
		DestroyWindow(_wnd);
		UnregisterClass(_title.c_str(), _instance);
	}
}