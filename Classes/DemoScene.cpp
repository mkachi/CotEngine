#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	entity = new Entity("Test");
	entity->AddComponent<AudioListener>()->Init();
	entity->AddComponent<SpriteRenderer>()->Init("Test.png");
	entity->AddComponent<AudioSource>()->Init("Test.wav")->Play();
	entity->SetPosition(Vec2(400, 300));
	this->AddEntity(entity);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}