#include "physics/CotPhysics.h"

namespace Cot
{
	bool IntersectRect(Rect& rect1, Rect& rect2)
	{
		return !(
			rect1.GetMaxX() < rect2.GetMinX() ||
			rect2.GetMaxX() < rect1.GetMinX() ||
			rect1.GetMaxY() < rect2.GetMinY() ||
			rect2.GetMaxY() < rect1.GetMinY());
	}

	bool IntersectCircle(Circle& circle1, Circle& circle2)
	{
		float distance = Vec2::Distance(circle1.center, circle2.center);
		float addR = circle1.r + circle2.r;

		if (distance <= addR)
		{
			return true;
		}
		return false;
	}

	bool IntersectRectCircle(Rect& rect, Circle& circle)
	{
		Vec2 center(rect.GetMidX(), rect.GetMidY());

		float w = rect.size.width / 2;
		float h = rect.size.height / 2;

		float dx = std::abs(rect.origin.x - center.x);
		float dy = std::abs(rect.origin.y - center.y);

		if (dx > (circle.r + w) || dy > (circle.r + h))
		{
			return false;
		}

		Vec2 distance(
			std::abs(center.x - rect.origin.x - w), 
			std::abs(center.y - rect.origin.y - h));

		if (distance.x <= w || distance.y <= h)
		{
			return true;
		}

		float cornerDistanceSq = powf(distance.x - w, 2) + powf(distance.y - h, 2);
		return (cornerDistanceSq <= powf(circle.r, 2));
	}
}