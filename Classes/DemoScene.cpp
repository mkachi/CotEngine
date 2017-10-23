#include "DemoScene.h"
#include "TestComponent.h"

using namespace Cot;

bool DemoScene::Init()
{
	for (int i = 0; i < 20; ++i)
	{
		entity[i] = new Entity(ToString(i));
		entity[i]->AddComponent<TestComponent>()->Init(ToString(i));
		this->AddEntity(entity[i]);
	}

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}