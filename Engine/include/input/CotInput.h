#pragma once

#include "input/CotInputDevice.h"

namespace Cot
{
	COT_API void RegisteInputDevice(InputDevice* device);
	COT_API void DestroyInputDevice();

	COT_API bool IsKeyDown(KeyCode code);
	COT_API bool IsKeyStay(KeyCode code);
	COT_API bool IsKeyUp(KeyCode code);

	COT_API bool IsMouseDown(MouseButton button);
	COT_API bool IsMouseStay(MouseButton button);
	COT_API bool IsMouseUp(MouseButton button);

	COT_API Vec2 GetMousePosition();
	COT_API float GetMouseWheel();
}