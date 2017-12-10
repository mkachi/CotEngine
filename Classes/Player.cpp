#include "Player.h"
#include "Gravity.h"
#include "EffectFactory.h"
#include "UserDefault.h"

using namespace Cot;

Player* Player::Init(float speed, Scene* scene)
{
	_factory = new EffectFactory(GetOwner(), scene);

	_speed = speed;
	_beforeState = _state = PlayerState::Idle;

	SpriteRenderer* renderer = GetOwner()->GetComponent<SpriteRenderer>();
	_animation = GetOwner()->GetComponent<Animation>();
	_collider = GetOwner()->GetComponent<BoxCollider>();
	_gravity = GetOwner()->GetComponent<Gravity>();
	_clampValue = {
		renderer->GetSize().width / 2,
		SCREEN_WIDTH - (renderer->GetSize().width / 2)
	};

	return this;
}

void Player::StateUpdate()
{
	if (!_animation->IsPlay())
	{
		_factory->DisableAllEffect();
	}

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
		_factory->Spawn(EffectType::Jump);
		break;

	case PlayerState::JumpAttack:
		_animation->SetData(_jumpAttack);
		break;

	case PlayerState::Attack:
		_animation->SetData(_attack);
		_factory->Spawn(EffectType::Attack);
		break;

	case PlayerState::Shield:
		_animation->SetData(_shield);
		_factory->Spawn(EffectType::Shield);
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
	if (_collider->IsEnter() &&
		_collider->GetTarget() != nullptr &&
		_collider->GetTarget()->GetName() == "Floor")
	{
		_gravity->SetGround(true);
	}
	else
	{
		_gravity->SetGround(false);
	}

	//if (IsKeyStay(KeyCode::Left))
	//{
	//	if (!_gravity->IsGround())
	//	{
	//		return;
	//	}

	//	_state = PlayerState::Move;
	//	GetOwner()->SetPositionX(
	//		Clamp(GetOwner()->GetPosition().x - _speed * time.GetDeltaTime(), _clampValue.first, _clampValue.second));
	//}

	//if (IsKeyStay(KeyCode::Right))
	//{
	//	if (!_gravity->IsGround())
	//	{
	//		return;
	//	}

	//	_state = PlayerState::Move;
	//	GetOwner()->SetPositionX(
	//		Clamp(GetOwner()->GetPosition().x + _speed * time.GetDeltaTime(), _clampValue.first, _clampValue.second));
	//}

	if (IsKeyDown(KeyCode::Up))
	{
		if (!_gravity->IsGround())
		{
			return;
		}
		_state = PlayerState::Jump;
		_gravity->SetGround(false);
		_gravity->AddForce(3000.0f);
	}

	if (IsKeyStay(KeyCode::Z))
	{
		if (_state == PlayerState::Jump)
		{
			_state = PlayerState::JumpAttack;
		}
		else
		{
			_state = PlayerState::Attack;
		}
	}

	if (IsKeyStay(KeyCode::Down))
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
	AnimationClip& jumpAttack,
	AnimationClip& attack,
	AnimationClip& shield,
	AnimationClip& skill)
{
	_idle = idle;
	_jump = jump;
	_jumpAttack = jumpAttack;
	_attack = attack;
	_shield = shield;
	_skill = skill;
}