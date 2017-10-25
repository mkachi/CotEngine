#include "DemoScene.h"
#include "TestComponent.h"

using namespace Cot;

bool DemoScene::Init()
{
	for (int i = 0; i < ENTITY_COUNT; ++i)
	{
		entity[i] = new Entity(ToString(i));
		entity[i]->AddComponent<SpriteRenderer>()->Init("Circle.png");
		entity[i]->SetScale(Vec3(0.3f, 0.3f, 0.0f));
		entity[i]->AddComponent<TestComponent>()->Init(ToString(i));
		this->AddEntity(entity[i]);
	}
	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}