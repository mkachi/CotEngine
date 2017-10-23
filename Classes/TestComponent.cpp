#include "TestComponent.h"

using namespace Cot;

TestComponent* TestComponent::Init(const string& str)
{
	_str = str;
	return this;
}

void TestComponent::Update(Cot::Time& time)
{
	if (IsKeyStay(KeyCode::A))
	{
		printf("%s\n", _str.c_str());
	}
}