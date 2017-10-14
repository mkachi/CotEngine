#include "input/CotInput.h"

namespace Cot
{
	static InputDevice* _device = nullptr;

	void RegisterInputDevice(InputDevice* device)
	{
		_device = device;
	}

	bool IsKeyDown(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
		return _device->GetKeyState()[_device->DikToKeyCode(code)] & 0x80;
	}

	bool IsKeyUp(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
		return false;
	}
	
	bool IsKeyPressed(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
		return false;
	}

	Vec2 GetMousePosition()
	{
		if (_device == nullptr)
		{
			return Vec2::Zero;
		}
	}

	bool IsMouseDown(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}

		switch (code)
		{
		case KeyCode::MouseLButton: return (_device->GetMouseState().rgbButtons[0] & 0x80);
		case KeyCode::MouseRButton: return (_device->GetMouseState().rgbButtons[1] & 0x80);
		case KeyCode::MouseMButton: return (_device->GetMouseState().rgbButtons[2] & 0x80);
		}
	}

	bool IsMouseUp(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}

		switch (code)
		{
		case KeyCode::MouseLButton: return (_device->GetMouseState().rgbButtons[0] & 0x80);
		case KeyCode::MouseRButton: return (_device->GetMouseState().rgbButtons[1] & 0x80);
		case KeyCode::MouseMButton: return (_device->GetMouseState().rgbButtons[2] & 0x80);
		}
	}

	bool IsMousePressed(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}

		switch (code)
		{
		case KeyCode::MouseLButton: return (_device->GetMouseState().rgbButtons[0] & 0x80);
		case KeyCode::MouseRButton: return (_device->GetMouseState().rgbButtons[1] & 0x80);
		case KeyCode::MouseMButton: return (_device->GetMouseState().rgbButtons[2] & 0x80);
		}
	}
}