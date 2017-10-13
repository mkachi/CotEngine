#pragma once

#include <CotEngine.h>

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* entity;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};