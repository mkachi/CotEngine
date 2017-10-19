#pragma once

#include <CotEngine.h>

Component(TestComponent)
{
	COT_COMPONENT(TestComponent);
public:
	void OnTriggerEnter(Cot::Entity* entity) override;
	void OnTriggerStay(Cot::Entity* entity) override;
	void OnTriggerExit(Cot::Entity* entity) override;

};