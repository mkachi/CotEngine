#pragma once

#include "CotRule.h"
#include "CotScene.h"
#include "render/CotIGraphics.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	class COT_API Application final
	{
	private:
		HWND			_wnd;
		HINSTANCE		_instance;
		wstring			_title;
		IGraphics*		_graphics;

		static LRESULT CALLBACK MsgProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

		bool InitGraphcis(int width, int height, bool fullScreen);

	public:
		Application();
		~Application();

		bool Init(HINSTANCE instance, const string& title, uint width, uint height, bool fullScreen = false);
		void RunWithScene(Scene* scene);
		void Destroy();

	};
}