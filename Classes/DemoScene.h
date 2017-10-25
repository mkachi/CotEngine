#pragma once

#include <CotEngine.h>

#define ENTITY_COUNT 100

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* entity[ENTITY_COUNT];

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};