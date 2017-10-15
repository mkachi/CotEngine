#include "input/CotInput.h"

namespace Cot
{
	static InputDevice* _device = nullptr;

	void RegisteInputDevice(InputDevice* device)
	{
		_device = device;
	}

	void UpdateKeyDown(uint code)
	{
		if (_device != nullptr)
		{
			_device->UpdateKeyDown(code);
		}
	}

	void UpdateKeyUp(uint code)
	{
		if (_device != nullptr)
		{
			_device->UpdateKeyUp(code);
		}
	}

	void UpdateMouseDown(MouseButton button)
	{
		if (_device != nullptr)
		{
			_device->UpdateMouseDown(button);
		}
	}

	void UpdateMouseUp(MouseButton button)
	{
		if (_device != nullptr)
		{
			_device->UpdateMouseUp(button);
		}
	}

	bool IsKeyDown(KeyCode code)
	{
		if (_device != nullptr)
		{
			return _device->IsKeyDown(code);
		}
		return false;
	}

	bool IsKeyUp(KeyCode code)
	{
		if (_device != nullptr)
		{
			return _device->IsKeyUp(code);
		}
		return false;
	}
	
	bool IsKeyStay(KeyCode code)
	{
		if (_device != nullptr)
		{
			return _device->IsKeyStay(code);
		}
		return false;
	}

	Vec2 GetMousePosition()
	{
		if (_device != nullptr)
		{
			return _device->GetMousePosition();
		}
		return Vec2::Zero;
	}

	bool IsMouseDown(MouseButton code)
	{
		if (_device != nullptr)
		{
			return _device->IsMouseDown(code);
		}
		return false;
	}

	bool IsMouseUp(MouseButton code)
	{
		if (_device != nullptr)
		{
			return _device->IsMouseUp(code);
		}
		return false;
	}

	bool IsMouseStay(MouseButton code)
	{
		if (_device != nullptr)
		{
			return _device->IsMouseStay(code);
		}
		return false;
	}

	void InputClear()
	{
		if (_device != nullptr)
		{
			return _device->Clear();
		}
	}
}