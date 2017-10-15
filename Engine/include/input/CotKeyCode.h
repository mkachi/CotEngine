#pragma once

#include "base/CotRule.h"

namespace Cot
{
	enum class KeyCode
	{
		Esc = 0,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		PrintScreen, // SYSRQ
		Scroll,		// scroll lock
		Pause,
		_0,
		_1,
		_2,
		_3,
		_4,
		_5,
		_6,
		_7,
		_8,
		_9,
		Minus,		// -
		Equals,		// =
		BackSpace,
		Tab,
		Q,
		W,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		LBracket,	// [
		RBracket,	// ]
		Enter,
		LCtrl,
		RCtrl,
		A,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		Semicolon,	// ; :
		Apostrophe, // ' "
		Grave,		// ` ~
		LShift,
		BackSlash,	// \ //
		Z,
		X,
		C,
		V,
		B,
		N,
		M,
		Comma,		// ,
		Period,		// .
		Slash,		// /
		RShift,
		LAlt,
		RAlt,
		LWin,
		RWin,
		CapsLock,
		Up,
		Down,
		Left,
		Right,
		PgUp,
		PgDown,
		Insert,
		Home,
		Delete,
		End,
		SpaceBar,
		Num_Lock,
		Num_Slash,
		Num_Multiply,
		Num_Minus,
		Num_Plus,
		Num_Enter,
		Num_Decimal,
		Num_0,
		Num_1,
		Num_2,
		Num_3,
		Num_4,
		Num_5,
		Num_6,
		Num_7,
		Num_8,
		Num_9,
		KEYBOARD_END,
	};
	enum class MouseButton
	{
		LButton = 0,
		MButton,
		RButton,
		MOUSE_END,
	};
}