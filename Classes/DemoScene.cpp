#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	//Root
	root = new Entity("root");
	root->SetPosition(Vec3(0.0f, 0.0f));
	this->AddEntity(root);

	//Ob pool initialize
	for (int i = 0; i < 2; i++)
	{
		testEntity[i] = new Entity(ToString(i));
		testEntity[i]->SetParent(root);
		testEntity[i]->AddComponent<SpriteRenderer>()->Init("testPng.png");
		testEntity[i]->SetPosition(Vec3(120 * i, 300));
		testEntity[i]->AddComponent<BoxCollider>()->SetSpriteSize();
		this->AddEntity(testEntity[i]);
	} // 100 100

	// 256 256
	//Mover object
	entity2 = new Entity("Test2");
	entity2->SetParent(root);
	entity2->AddComponent<SpriteRenderer>()->Init("testPng.png");
	entity2->AddComponent<TestComponent>();
	entity2->SetPosition(Vec3(0.0f, 300.0f, 0.0f));
	entity2->AddComponent<BoxCollider>()->SetSpriteSize();
	this->AddEntity(entity2);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyStay(KeyCode::A))
		entity2->SetPositionX(entity2->GetPosition().x - 100.0f * time.GetDeltaTime());
	if (IsKeyStay(KeyCode::D))
		entity2->SetPositionX(entity2->GetPosition().x + 100.0f * time.GetDeltaTime());
	if (IsKeyStay(KeyCode::W))
		entity2->SetPositionY(entity2->GetPosition().y - 100.0f * time.GetDeltaTime());
	if (IsKeyStay(KeyCode::S))
		entity2->SetPositionY(entity2->GetPosition().y + 100.0f * time.GetDeltaTime());
}