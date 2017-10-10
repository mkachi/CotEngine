#pragma once

#include <Windows.h>
#include "CotRule.h"

namespace Cot
{
	class COT_API Application final
	{
	private:
		HWND		_wnd;
		HINSTANCE	_instance;
		wstring		_title;

		static LRESULT CALLBACK MsgProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

	public:
		Application();
		~Application();

		bool Init(HINSTANCE instance, const string& title, int width, int height, bool fullScreen);
		void Run();
		void Destroy();

	};
}