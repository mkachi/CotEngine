#include "TestComponent.h"

void TestComponent::Awake()
{
	_delayCount = 0.0f;
	_show = false;
}

void TestComponent::Update(Time& time)
{
	_delayCount += time.GetDeltaTime();
	if (_delayCount >= 1.0f)
	{
		_show = true;
		_delayCount = 0.0f;
	}
}

void TestComponent::OnTriggerEnter(Entity* entity)
{
	printf("Enter %s\n", entity->GetName().c_str());
}

void TestComponent::OnTriggerStay(Entity* entity)
{
	if (_show)
	{
		_show = false;
		printf("Stay %s\n", entity->GetName().c_str());
	}
}

void TestComponent::OnTriggerExit(Entity* entity)
{
	printf("Exit %s\n", entity->GetName().c_str());
}