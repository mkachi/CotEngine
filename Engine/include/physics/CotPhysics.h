#pragma once

#include "math/CotMath.h"

namespace Cot
{
	COT_API inline bool IntersectRect(Rect& rect1, Rect& rect2);
	COT_API inline bool IntersectCircle(Circle& circle1, Circle& circle2);

	COT_API inline bool IntersectRectCircle(Rect& rect, Circle& circle);

	COT_API inline bool PointInRect(Rect& rect, Vec2& position);
}