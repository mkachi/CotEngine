#pragma once

#include <CotEngine.h>

Component(Gravity)
{
	COT_COMPONENT(Gravity);
private:
	float	_gravityPower;
	float	_speed;
	bool	_ground;

public:
	Gravity* Init(float gravityPower);

	void Reset() override;
	void LateUpdate(Cot::Time& time) override;
	void AddForce(float power);

	void SetGround(bool value);
	bool IsGround() { return _ground; }

};