#pragma once

#include <CotEngine.h>
#include "TestComponent.h"

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* button;
	Cot::PrograssBar* prograssBar;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};