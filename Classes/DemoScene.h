#pragma once

#include <CotEngine.h>
#include "TestComponent.h"

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* root;
	Cot::Entity* testEntity[10];

	Cot::Entity* entity2;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};