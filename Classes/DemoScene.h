#pragma once

#include <CotEngine.h>

class GameScene
	: public Cot::Scene
{
private:
	Cot::Entity* _player;

public:
	bool Init() override;
	void Update(Cot::Time& time) override;

};