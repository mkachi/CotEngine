#pragma once

#include <CotEngine.h>
#include <random>

Component(TestComponent)
{
	COT_COMPONENT(TestComponent);
private:
	string	_str;
	Cot::Vec3	_direction;
	float	_count;

	float GetRandom(float min, float max);

public:
	TestComponent* Init(const string& str);

	string GetStr() { return _str; }

	void Update(Cot::Time& time) override;

};