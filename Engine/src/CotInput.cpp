#include "input/CotInput.h"

namespace Cot
{
	static InputDevice* _device = nullptr;

	void RegisteInputDevice(InputDevice* device)
	{
		_device = device;
	}

	void DestroyInputDevice()
	{
		SafeDelete(_device);
	}

	bool IsKeyDown(KeyCode code)
	{
		return _device->IsKeyDown(code);
	}

	bool IsKeyStay(KeyCode code)
	{
		return _device->IsKeyStay(code);
	}

	bool IsKeyUp(KeyCode code)
	{
		return _device->IsKeyUp(code);
	}

	bool IsMouseDown(MouseButton button)
	{
		return _device->IsMouseDown(button);
	}

	bool IsMouseStay(MouseButton button)
	{
		return _device->IsMouseStay(button);
	}

	bool IsMouseUp(MouseButton button)
	{
		return _device->IsMouseUp(button);
	}

	Vec2 GetMousePosition()
	{
		return _device->GetMousePosition();
	}

	float GetMouseWheel()
	{
		return _device->GetMouseWheel();
	}
}