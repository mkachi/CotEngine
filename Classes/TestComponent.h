#pragma once

#include <CotEngine.h>

using namespace Cot;

Component(TestComponent)
{
	COT_COMPONENT(TestComponent);
private:
	float	_delayCount;
	bool	_show;

public:
	void Awake() override;

	void Update(Time& time) override;

	void OnTriggerEnter(Entity* entity) override;
	void OnTriggerStay(Entity* entity) override;
	void OnTriggerExit(Entity* entity) override;

};