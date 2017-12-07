#pragma once

#include <CotEngine.h>

enum class PlayerState
{
	Idle,
	Jump,
	Move,
	Attack,
	Shield,
	Skill,
};

class Gravity;
Component(Player)
{
	using ClampValue = std::pair<float, float>;
	using AnimationClip = std::vector<Cot::AnimationData>;
	COT_COMPONENT(Player);
private:
	float				_speed;
	ClampValue			_clampValue;

	PlayerState			_state;
	PlayerState			_beforeState;
	Cot::Animation*		_animation;
	Cot::BoxCollider*	_collider;
	Gravity*			_gravity;

	AnimationClip	_idle;
	AnimationClip	_jump;
	AnimationClip	_move;
	AnimationClip	_attack;
	AnimationClip	_shield;
	AnimationClip	_skill;

	void StateUpdate();

public:
	Player* Init(float speed);

	void Update(Cot::Time& time) override;
	void SetAnimationData(
		AnimationClip& idle,
		AnimationClip& jump,
		AnimationClip& move,
		AnimationClip& attack,
		AnimationClip& shield,
		AnimationClip& skill);

};