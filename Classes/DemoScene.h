#pragma once

#include <CotEngine.h>

class DemoScene
	: public Cot::Scene
{
public:
	bool Init() override;
	void Update(Cot::Time& time) override;
	void Test() {}

};