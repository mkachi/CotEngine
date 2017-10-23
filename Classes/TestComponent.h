#pragma once

#include <CotEngine.h>

Component(TestComponent)
{
	COT_COMPONENT(TestComponent);
private:
	string _str;

public:
	TestComponent* Init(const string& str);

	string GetStr() { return _str; }

	void Update(Cot::Time& time) override;

};