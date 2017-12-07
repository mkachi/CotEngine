#include "Gravity.h"

using namespace Cot;

Gravity* Gravity::Init(float gravityPower = 1.0f)
{
	Reset();
	_gravityPower = gravityPower;
	return this;
}

void Gravity::Reset()
{
	_ground = false;
	_speed = 0.0f;
}

void Gravity::LateUpdate(Time& time)
{
	if (_ground)
	{
		return;
	}

	_speed += _gravityPower;
	float y = GetOwner()->GetPosition().y;
	GetOwner()->SetPositionY((y + _speed * time.GetDeltaTime()));
}

void Gravity::AddForce(float power)
{
	_speed = 0;
	_speed = -power;
}

void Gravity::SetGround(bool value)
{
	_ground = value;
}