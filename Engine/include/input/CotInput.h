#pragma once

#include "CotInputDevice.h"
#include "math/CotVec2.h"

namespace Cot
{
	COT_API inline void RegisterInputDevice(InputDevice* device);

	COT_API inline bool IsKeyDown(KeyCode code);
	COT_API inline bool IsKeyUp(KeyCode code);
	COT_API inline bool IsKeyPressed(KeyCode code);

	COT_API inline Vec2 GetMousePosition();
	COT_API inline bool IsMouseDown(KeyCode code);
	COT_API inline bool IsMouseUp(KeyCode code);
	COT_API inline bool IsMousePressed(KeyCode code);
}