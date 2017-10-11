#include "base/CotApplication.h"
#include "base/CotSceneManager.h"
#include "render/CotDx9Device.h"

namespace Cot
{
	Application::Application()
		: _graphics(nullptr)
	{	}

	Application::~Application()
	{	}

	LRESULT Application::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
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
		_graphics->AddRenderer(nullptr);

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

		ShowWindow(_wnd, SW_SHOWDEFAULT);
		UpdateWindow(_wnd);

		return true;
	}

	void Application::RunWithScene(IScene* scene)
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
				_graphics->Render();
			}
		}
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
		_graphics->Destroy();
		DestroyWindow(_wnd);
		UnregisterClass(_title.c_str(), _instance);
	}
}