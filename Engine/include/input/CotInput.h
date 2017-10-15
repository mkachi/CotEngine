#pragma once

#include "CotInputDevice.h"

namespace Cot
{
	COT_API inline void RegisteInputDevice(InputDevice* device);

	COT_API inline void UpdateKeyDown(uint code);
	COT_API inline void UpdateKeyUp(uint code);

	COT_API inline void UpdateMouseDown(MouseButton button);
	COT_API inline void UpdateMouseUp(MouseButton button);

	COT_API inline bool IsKeyDown(KeyCode code);
	COT_API inline bool IsKeyUp(KeyCode code);
	COT_API inline bool IsKeyStay(KeyCode code);

	COT_API inline Vec2 GetMousePosition();
	COT_API inline bool IsMouseDown(MouseButton code);
	COT_API inline bool IsMouseUp(MouseButton code);
	COT_API inline bool IsMouseStay(MouseButton code);

	COT_API inline void InputClear();
}