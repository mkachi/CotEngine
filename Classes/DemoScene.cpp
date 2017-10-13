#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	entity = new Entity("Test");
	entity->AddComponent<SpriteRenderer>()->Init("Test.png");
	this->AddEntity(entity);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
	entity->SetPosition(Vec3(500.0f, 500.0f, 0.0f));
	entity->SetScale(Vec3(-1.0f, 1.0f, 1.0f));
}