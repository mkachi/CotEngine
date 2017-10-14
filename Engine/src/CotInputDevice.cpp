#include "input/CotInputDevice.h"

namespace Cot
{
	InputDevice::InputDevice()
		: _directInput(nullptr)
		, _keyboard(nullptr)
		, _mouse(nullptr)
		, _mousePosition(Vec2::Zero)
	{	}

	InputDevice::~InputDevice()
	{	}

	bool InputDevice::Init(HINSTANCE instance, HWND wnd, int width, int height)
	{
		CreateKeyCodeTable();

		_screenWidth = width;
		_screenHeight = height;

		HRESULT result;

		result = DirectInput8Create(instance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_directInput, NULL);
		if (FAILED(result))
		{
			return false;
		}

		result = _directInput->CreateDevice(GUID_SysKeyboard, &_keyboard, NULL);
		if (FAILED(result))
		{
			return false;
		}

		result = _keyboard->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(result))
		{
			return false;
		}

		result = _keyboard->SetCooperativeLevel(wnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
		if (FAILED(result))
		{
			return false;
		}

		result = _keyboard->Acquire();
		if (FAILED(result))
		{
			return false;
		}

		result = _directInput->CreateDevice(GUID_SysMouse, &_mouse, NULL);
		if (FAILED(result))
		{
			return false;
		}

		result = _mouse->SetDataFormat(&c_dfDIMouse);
		if (FAILED(result))
		{
			return false;
		}

		result = _mouse->SetCooperativeLevel(wnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
		if (FAILED(result))
		{
			return false;
		}

		result = _mouse->Acquire();
		if (FAILED(result))
		{
			return false;
		}

		return true;
	}

	bool InputDevice::ReadKeyState()
	{
		HRESULT result = _keyboard->GetDeviceState(sizeof(_keyboard), (LPVOID)&_keyState);
		if (FAILED(result))
		{
			if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)) 
			{
				_keyboard->Acquire(); 
			}
			else 
			{ 
				return false; 
			}
		}
		return true;
	}

	bool InputDevice::ReadMouseState()
	{
		HRESULT result = _mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&_mouseState);
		if (FAILED(result))
		{
			if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
			{
				_mouse->Acquire();
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	void InputDevice::ProcessInput()
	{
		_mousePosition.x += _mouseState.lX;
		_mousePosition.y += _mouseState.lY;

		if (_mousePosition.x < 0.0f) { _mousePosition.x = 0.0f; }
		if (_mousePosition.y < 0.0f) { _mousePosition.y = 0.0f; }

		if (_mousePosition.x > _screenWidth) { _mousePosition.x = _screenWidth; }
		if (_mousePosition.y > _screenHeight) { _mousePosition.y = _screenHeight; }
	}

	void InputDevice::Destroy()
	{
		if (_mouse != nullptr)
		{
			_mouse->Unacquire();
			_mouse->Release();
			_mouse = nullptr;
		}

		if (_keyboard != nullptr)
		{
			_keyboard->Unacquire();
			_keyboard->Release();
			_keyboard = nullptr;
		}

		SafeRelease(_directInput);
	}

	void InputDevice::Update()
	{
		if ((!ReadKeyState()) && (!ReadMouseState()))
		{
			return;
		}
		ProcessInput();
	}

	void InputDevice::CreateKeyCodeTable()
	{
		_swaper = {
			{	KeyCode::Esc,				DIK_ESCAPE			},
			{	KeyCode::F1,				DIK_F1				},
			{	KeyCode::F2,				DIK_F2				},
			{	KeyCode::F3,				DIK_F3				},
			{	KeyCode::F4,				DIK_F4				},
			{	KeyCode::F5,				DIK_F5				},
			{	KeyCode::F6,				DIK_F6				},
			{	KeyCode::F7,				DIK_F7				},
			{	KeyCode::F8,				DIK_F8				},
			{	KeyCode::F9,				DIK_F9				},
			{	KeyCode::F10,				DIK_F10				},
			{	KeyCode::F11,				DIK_F11				},
			{	KeyCode::F12,				DIK_F12				},
			{	KeyCode::PrintScreen,		DIK_SYSRQ			},
			{	KeyCode::Scroll,			DIK_SCROLL			},
			{	KeyCode::Pause,				DIK_PAUSE			},
			{	KeyCode::_0,				DIK_1				},
			{	KeyCode::_1,				DIK_2				},
			{	KeyCode::_2,				DIK_3				},
			{	KeyCode::_3,				DIK_4				},
			{	KeyCode::_4,				DIK_5				},
			{	KeyCode::_5,				DIK_6				},
			{	KeyCode::_6,				DIK_7				},
			{	KeyCode::_7,				DIK_8				},
			{	KeyCode::_8,				DIK_9				},
			{	KeyCode::_9,				DIK_0				},
			{	KeyCode::Minus,				DIK_MINUS			},
			{	KeyCode::Equals,			DIK_EQUALS			},
			{	KeyCode::BackSpace,			DIK_BACKSPACE		},
			{	KeyCode::Tab,				DIK_TAB				},
			{	KeyCode::Q,					DIK_Q				},
			{	KeyCode::W,					DIK_W				},
			{	KeyCode::E,					DIK_E				},
			{	KeyCode::R,					DIK_R				},
			{	KeyCode::T,					DIK_T				},
			{	KeyCode::Y,					DIK_Y				},
			{	KeyCode::U,					DIK_U				},
			{	KeyCode::I,					DIK_I				},
			{	KeyCode::O,					DIK_O				},
			{	KeyCode::P,					DIK_P				},
			{	KeyCode::LBracket,			DIK_LBRACKET		},
			{	KeyCode::RBracket,			DIK_RBRACKET		},
			{	KeyCode::Enter,				DIK_RETURN			},
			{	KeyCode::LCtrl,				DIK_LCONTROL		},
			{	KeyCode::A,					DIK_A				},
			{	KeyCode::S,					DIK_S				},
			{	KeyCode::D,					DIK_D				},
			{	KeyCode::F,					DIK_F				},
			{	KeyCode::G,					DIK_G				},
			{	KeyCode::H,					DIK_H				},
			{	KeyCode::J,					DIK_J				},
			{	KeyCode::K,					DIK_K				},
			{	KeyCode::L,					DIK_L				},
			{	KeyCode::Semicolon,			DIK_SEMICOLON		},
			{	KeyCode::Apostrophe, 		DIK_APOSTROPHE		},
			{	KeyCode::Grave,				DIK_GRAVE			},
			{	KeyCode::LSHIFT,			DIK_LSHIFT			},
			{	KeyCode::BackSlash,			DIK_BACKSLASH		},
			{	KeyCode::Z,					DIK_Z				},
			{	KeyCode::X,					DIK_X				},
			{	KeyCode::C,					DIK_C				},
			{	KeyCode::V,					DIK_V				},
			{	KeyCode::B,					DIK_B				},
			{	KeyCode::N,					DIK_N				},
			{	KeyCode::M,					DIK_M				},
			{	KeyCode::Comma,				DIK_COMMA			},
			{	KeyCode::Period,			DIK_PERIOD			},
			{	KeyCode::Slash,				DIK_SLASH			},
			{	KeyCode::RShift,			DIK_RSHIFT			},
			{	KeyCode::LAlt,				DIK_LALT			},
			{	KeyCode::RAlt,				DIK_RALT			},
			{	KeyCode::LWin,				DIK_LWIN			},
			{	KeyCode::RWin,				DIK_RWIN			},
			{	KeyCode::CapsLock,			DIK_CAPSLOCK		},
			{	KeyCode::Up,				DIK_UPARROW			},
			{	KeyCode::Down,				DIK_DOWNARROW		},
			{	KeyCode::Left,				DIK_LEFTARROW		},
			{	KeyCode::Right,				DIK_RIGHTARROW		},
			{	KeyCode::PgUp,				DIK_PGUP			},
			{	KeyCode::PgDown,			DIK_PGDN			},
			{	KeyCode::Insert,			DIK_INSERT			},
			{	KeyCode::Home,				DIK_HOME			},
			{	KeyCode::Delete,			DIK_DELETE			},
			{	KeyCode::End,				DIK_END				},
			{	KeyCode::Num_Lock,			DIK_NUMLOCK			},
			{	KeyCode::Num_Slash,			DIK_NUMPADSLASH		},
			{	KeyCode::Num_Multiple,		DIK_NUMPADSTAR		},
			{	KeyCode::Num_Minus,			DIK_NUMPADMINUS		},
			{	KeyCode::Num_Plus,			DIK_NUMPADPLUS		},
			{	KeyCode::Num_Enter,			DIK_NUMPADENTER		},
			{	KeyCode::Num_Decimal,		DIK_NUMPADPERIOD	},
			{	KeyCode::Num_0,				DIK_NUMPAD0			},
			{	KeyCode::Num_1,				DIK_NUMPAD1			},
			{	KeyCode::Num_2,				DIK_NUMPAD2			},
			{	KeyCode::Num_3,				DIK_NUMPAD3			},
			{	KeyCode::Num_4,				DIK_NUMPAD4			},
			{	KeyCode::Num_5,				DIK_NUMPAD5			},
			{	KeyCode::Num_6,				DIK_NUMPAD6			},
			{	KeyCode::Num_7,				DIK_NUMPAD7			},
			{	KeyCode::Num_8,				DIK_NUMPAD8			},
			{	KeyCode::Num_9,				DIK_NUMPAD9			},
		};
	}

	uint InputDevice::DikToKeyCode(KeyCode code)
	{
		return _swaper[code];
	}
}