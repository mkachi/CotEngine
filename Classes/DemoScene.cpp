#include "DemoScene.h"
#include <physics/CotPhysics.h>

using namespace Cot;

bool DemoScene::Init()
{
	entity = new Entity("Parent");
	entity->AddComponent<SpriteRenderer>()->Init("Circle.png");
	entity->SetPosition(Vec3(0.0f, 0.0f, 0.0f));
	this->AddEntity(entity);

	Entity* entity2 = new Entity("Child");
	entity2->AddComponent<SpriteRenderer>()->Init("Circle.png");
	entity2->SetScale(Vec3(0.5f, 0.5f, 0.5f));
	entity2->SetPosition(Vec3(200.0f, 0.0f, 0.0f));
	this->AddEntity(entity2);

	entity2->SetParent(entity);
//	entity->AddChild(entity2);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyStay(KeyCode::A))
	{
		entity->SetPositionX(entity->GetPosition().x + 10.0f * time.GetDeltaTime());
	}
}