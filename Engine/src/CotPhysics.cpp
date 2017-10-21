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
		Vec2 distance = Vec2(
			std::abs(circle.center.x - rect.origin.x),
			std::abs(circle.center.y - rect.origin.y));

		if (distance.x > (rect.size.width / 2 + circle.r) ||
			distance.y > (rect.size.height / 2 + circle.r))
		{
			return false;
		}

		if (distance.x <= (rect.size.width / 2) ||
			distance.y <= (rect.size.height / 2))
		{
			return true;
		}

		Vec2 cornerDistance = Vec2(
			std::pow((distance.x - rect.size.width / 2), 2),
			std::pow((distance.y - rect.size.height / 2), 2)
		);
		return (cornerDistance <= std::pow(circle.r, 2));
	}
}