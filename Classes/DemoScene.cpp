#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	a = new Entity("a");
	a->AddComponent<SpriteRenderer>()->Init("Circle.png");
	a->SetPosition(Vec3(0.0f, 0.0f));
	this->AddEntity(a);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyDown(KeyCode::A))
	{
		printf("Down 1\n");
	}

	if (IsKeyDown(KeyCode::A))
	{
		printf("Down 2\n");
	}
}