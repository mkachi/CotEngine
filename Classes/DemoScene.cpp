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
}