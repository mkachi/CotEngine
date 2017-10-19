#include "TestComponent.h"

using namespace Cot;

void TestComponent::OnTriggerEnter(Entity* entity)
{
	printf("Enter : %s\n", entity->GetName().c_str());
}

void TestComponent::OnTriggerStay(Entity* entity)
{
	printf("Stay : %s\n", entity->GetName().c_str());
}

void TestComponent::OnTriggerExit(Entity* entity)
{
	printf("Exit : %s\n", entity->GetName().c_str());
}