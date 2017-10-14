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
	}

	bool IsKeyUp(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
	}
	
	bool IsKeyPressed(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
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
	}

	bool IsMouseUp(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
	}

	bool IsMousePressed(KeyCode code)
	{
		if (_device == nullptr)
		{
			return false;
		}
	}
}