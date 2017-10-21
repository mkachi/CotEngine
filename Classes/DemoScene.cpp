#include "DemoScene.h"
#include <physics/CotPhysics.h>

using namespace Cot;

bool DemoScene::Init()
{
	entity = new Entity("Test Entity");
	entity->AddComponent<SpriteRenderer>()->Init("Test.png");
	entity->AddComponent<TestComponent>();
	BoxCollider* collider1 = entity->AddComponent<BoxCollider>();
	collider1->SetSpriteSize();
	entity->SetPosition(Vec2(0.0f, 300.0f));
	this->AddEntity(entity);

	Entity* entity2 = new Entity("Test Entity");
	entity2->AddComponent<SpriteRenderer>()->Init("Circle.png");
	CircleCollider* collider2 = entity2->AddComponent<CircleCollider>();
	collider2->SetRadius(128.0f);
	entity2->SetPosition(Vec2(800.0f, 300.0f));
	this->AddEntity(entity2);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyStay(KeyCode::A))
	{
		entity->SetPositionX(entity->GetPosition().x + 100.0f * time.GetDeltaTime());
	}

	if (IsKeyDown(KeyCode::Q))
	{
		graphics->SetFullScreen(false);
	}

	if (IsKeyDown(KeyCode::W))
	{
		graphics->SetFullScreen(true);
	}

	if (IsKeyDown(KeyCode::E))
	{
		graphics->SetWinSize(Size(1280, 1280));
	}
}