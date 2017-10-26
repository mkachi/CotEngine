#pragma once

#include <CotEngine.h>
/*
class DemoScene
	: public Cot::Scene
{
private:
	Cot::Entity* a;
	Cot::Entity* b;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};
*/

class DemoScene
	: public Cot::Scene
{
private:
	int nowX, nowY;
	Cot::Entity* PPAP;
	Cot::Entity* CAMERA;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};