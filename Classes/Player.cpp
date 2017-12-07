#include "Player.h"
#include "Gravity.h"

using namespace Cot;

Player* Player::Init(float speed)
{
	_speed = speed;
	_beforeState = _state = PlayerState::Idle;

	SpriteRenderer* renderer = GetOwner()->GetComponent<SpriteRenderer>();
	_animation = GetOwner()->GetComponent<Animation>();
	_collider = GetOwner()->GetComponent<BoxCollider>();
	_gravity = GetOwner()->GetComponent<Gravity>();

	_clampValue = {
		renderer->GetSize().width / 2,
		1280 - (renderer->GetSize().width / 2)
	};
	return this;
}

void Player::StateUpdate()
{
	if (_beforeState == _state)
	{
		return;
	}

	_animation->Stop();
	switch (_state)
	{
	case PlayerState::Idle:
		_animation->SetData(_idle);
		break;

	case PlayerState::Jump:
		_animation->SetData(_jump);
		break;

	case PlayerState::Move:
		_animation->SetData(_move);
		break;

	case PlayerState::Attack:
		_animation->SetData(_attack);
		break;

	case PlayerState::Shield:
		_animation->SetData(_shield);
		break;

	case PlayerState::Skill:
		_animation->SetData(_skill);
		break;
	}
	_animation->Play();

	_beforeState = _state;
}

void Player::Update(Time& time)
{
	if (_collider->IsEnter())
	{
		_gravity->SetGround(true);
	}
	else
	{
		_gravity->SetGround(false);
	}

	if (IsKeyStay(KeyCode::Left))
	{
		_state = PlayerState::Move;
		GetOwner()->SetPositionX(
			Clamp(GetOwner()->GetPosition().x - _speed * time.GetDeltaTime(), _clampValue.first, _clampValue.second));
	}

	if (IsKeyStay(KeyCode::Right))
	{
		_state = PlayerState::Move;
		GetOwner()->SetPositionX(
			Clamp(GetOwner()->GetPosition().x + _speed * time.GetDeltaTime(), _clampValue.first, _clampValue.second));
	}

	if (IsKeyDown(KeyCode::Up))
	{
		_state = PlayerState::Jump;
	}

	if (IsKeyStay(KeyCode::Z))
	{
		_state = PlayerState::Attack;
	}

	if (IsKeyStay(KeyCode::X))
	{
		_state = PlayerState::Shield;
	}

	if (IsKeyStay(KeyCode::C))
	{
		_state = PlayerState::Skill;
	}
	StateUpdate();
}

void Player::SetAnimationData(
	AnimationClip& idle,
	AnimationClip& jump,
	AnimationClip& move,
	AnimationClip& attack,
	AnimationClip& shield,
	AnimationClip& skill)
{
	_idle = idle;
	_jump = jump;
	_move = move;
	_attack = attack;
	_shield = shield;
	_skill = skill;
}