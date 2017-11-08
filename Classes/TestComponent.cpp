#include "TestComponent.h"

using namespace Cot;

GravityBody* GravityBody::Init(ICollider* collider)
{
	Reset();
	_collider = collider;
	return this;
}

void GravityBody::AddForce(const Vec3& distance, float power)
{
	_force = (distance * power) + Vec3(0.0f, _gravityScale, 0.0f);
}

void GravityBody::SetGravityScale(float gravityScale)
{
	_gravityScale = gravityScale;
}

void GravityBody::Reset()
{
	_gravityScale = 9.8f;
	_collider = nullptr;
	_force = Vec3(0.0f, 0.0f, 0.0f);
}

void GravityBody::Update(Cot::Time& time)
{
	if (_collider->IsEnter())
	{
		return;
	}

	Vec3 movePositoin = Vec3(_force.x, _force.y + _gravityScale, _force.z) * time.GetDeltaTime();
	GetOwner()->SetPosition(GetOwner()->GetPosition() + movePositoin);
	_force = Vec3(0.0f, 0.0f, 0.0f);
}