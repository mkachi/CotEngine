#pragma once

#include <CotEngine.h>
#include "TestComponent.h"

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* scroll;
	Cot::Entity* test;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};