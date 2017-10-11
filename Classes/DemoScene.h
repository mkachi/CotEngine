#pragma once

#include <CotEngine.h>

class DemoScene
	: public Cot::IScene
{
public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};