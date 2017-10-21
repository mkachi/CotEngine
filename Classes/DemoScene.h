#pragma once

#include <CotEngine.h>

class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* entity;
	Cot::Circle	circle1;
	Cot::Rect	rect1;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};