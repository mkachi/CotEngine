#include "TestComponent.h"

using namespace Cot;

TestComponent* TestComponent::Init(const string& str)
{
	_str = str;
	this->CreateKeyListener();
	return this;
}

void TestComponent::Update(Cot::Time& time)
{
	if (GetKeyListener()->IsKeyDown(KeyCode::A))
	{
		printf("%s\n", _str.c_str());
	}
}