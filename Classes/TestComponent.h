#pragma once

#include <CotEngine.h>
#include <component/CotICollider.h>

Component(GravityBody)
{
	COT_COMPONENT(GravityBody);
private:
	Cot::ICollider* _collider;
	float			_gravityScale;
	Cot::Vec3		_force;

public:
	GravityBody* Init(Cot::ICollider* collider);

	void AddForce(const Cot::Vec3& distance, float power);

	void SetGravityScale(float gravityScale);
	float GetGravityScale() { return _gravityScale; }

	void Reset() override;
	void Update(Cot::Time& time) override;

};