#pragma once

#include <CotEngine.h>

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* entity[20];

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};