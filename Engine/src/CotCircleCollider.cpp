#include "component/CotCircleCollider.h"
#include "physics/CotPhysicsManager.h"

namespace Cot
{
	CircleCollider* CircleCollider::Init(float radius)
	{
		_radius = radius;
		return this;
	}

	void CircleCollider::Reset()
	{
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
}