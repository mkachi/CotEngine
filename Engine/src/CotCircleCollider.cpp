#include "component/CotCircleCollider.h"
#include "physics/CotPhysicsManager.h"

namespace Cot
{
	CircleCollider* CircleCollider::Init(float radius)
	{
		Reset();
		_radius = radius;
		return this;
	}

	void CircleCollider::Reset()
	{
		_enter = false;
		_collType = Type::Circle;
	}

	void CircleCollider::Update(Time& time)
	{
		PhysicsManager::GetInstance().Add(this);
	}

	void CircleCollider::SetRadius(float radius)
	{
		_radius = radius;
	}

	Circle CircleCollider::GetCircle()
	{
		Vec2 position = Vec2(_offset.x + GetOwner()->GetPosition().x, _offset.y + GetOwner()->GetPosition().y);
		return Circle(_radius, position);
	}

	void CircleCollider::SetOffset(const Vec2& offset)
	{
		_offset = offset;
	}
}