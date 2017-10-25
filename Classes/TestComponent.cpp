#include "TestComponent.h"

using namespace Cot;

TestComponent* TestComponent::Init(const string& str)
{
	_str = str;
	_count = 0.0f;
	_direction = Vec3(0.0f, 0.0f, 0.0f);
	return this;
}

void TestComponent::Update(Cot::Time& time)
{
	_count += time.GetDeltaTime();
	if (_count >= 2.0f)
	{
		_count = 0.0f;
		_direction = Vec3(GetRandom(-1.0f, 1.0f), GetRandom(-1.0f, 1.0f), 0.0f);
	}
	GetOwner()->SetPosition(GetOwner()->GetPosition() + _direction * (20.0f * time.GetDeltaTime()));

	if (GetOwner()->GetPosition().x <= 0.0f || GetOwner()->GetPosition().y <= 0.0f ||
		GetOwner()->GetPosition().x >= 800.0f || GetOwner()->GetPosition().y >= 600.0f)
	{
		GetOwner()->SetPosition(Vec3(400.0f, 300.0f, 0.0f));
	}
}

float TestComponent::GetRandom(float min, float max)
{
	std::random_device rd;
	std::default_random_engine engine{ rd() };
	std::uniform_real_distribution<float> dist{ min, max };
	return dist(engine);
}