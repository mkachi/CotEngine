#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	graphics->SetClearColor(Color(1.0f, 0.0f, 0.0f));
	entity = new Entity("TestEntity");
	SpriteRenderer* renderer = entity->AddComponent<SpriteRenderer>()->Init("Test.png");
	renderer->SetDepth(2);
	this->AddEntity(entity);

	Entity* _2 = new Entity("Temp");
	SpriteRenderer* ang = entity->AddComponent<SpriteRenderer>()->Init("Temp.png");
	ang->SetDepth(1);
	this->AddEntity(_2);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}