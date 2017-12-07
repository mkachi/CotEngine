#include "DemoScene.h"
#include "Player.h"
#include "Gravity.h"

using namespace Cot;

bool GameScene::Init()
{
#pragma region AudioListener
	Entity* audioListener = new Entity("Listener");
	audioListener->AddComponent<AudioListener>()->Init();
	this->AddEntity(audioListener);
#pragma endregion

#pragma region Floor
	Entity* floor = new Entity("Floor");
	SpriteRenderer* floorRenderer = floor->AddComponent<SpriteRenderer>()->Init("Resources/floor_temp.png");
	BoxCollider* collider = floor->AddComponent<BoxCollider>()->Init(floorRenderer->GetSize());
	floor->SetPosition(Vec3(1280 / 2, 720 - 58.5f, 0.0f));
	this->AddEntity(floor);
#pragma endregion

#pragma region Player
	_player = new Entity("Player");
	_player->AddComponent<SpriteRenderer>()->Init("Resources/Player/Player_temp_idle.png");
	_player->AddComponent<BoxCollider>()->SetSpriteSize();
	_player->AddComponent<Gravity>()->Init(1.0f);
	_player->AddComponent<Animation>()->Init(std::vector<AnimationData>(
	{ AnimationData("Resources/Player/Player_temp_idle.png") }), 0.1f);
	Player* info = _player->AddComponent<Player>()->Init(60.0f);
	_player->SetPosition(Vec3(1280 / 2, 0.0f, 0.0f));
	this->AddEntity(_player);

	info->SetAnimationData(
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_idle.png") }), // idle
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_jump.png") }), // jump
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_move.png") }), // move
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_attack.png") }), // attack
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_shield.png") }), // shield
		std::vector<AnimationData>({ AnimationData("Resources/Player/Player_temp_skill.png") })	// skill
	);
#pragma endregion

	return true;
}

void GameScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}