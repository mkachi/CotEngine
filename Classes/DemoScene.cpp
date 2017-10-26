#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	a = new Entity("a");
	a->AddComponent<SpriteRenderer>()->Init("Circle.png");
	a->SetPosition(Vec3(200.0f, 0));
	this->AddEntity(a);

	b = new Entity("b");
	b->AddComponent<SpriteRenderer>()->Init("Circle.png");
	b->SetPosition(Vec3(0, 0));
	this->AddEntity(b);

	this->CreateKeyListener();

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (this->GetKeyListener()->IsKeyDown(KeyCode::C))
	{
		a->SetPositionX(a->GetPosition().x + 10);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::A))
	{
		printf("a : World %f %f %f\n", a->GetPosition().x, a->GetPosition().y, a->GetPosition().z);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::S))
	{
		printf("b : World %f %f %f\n", b->GetPosition().x, b->GetPosition().y, b->GetPosition().z);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::D))
	{
		printf("a : Local %f %f %f\n", a->GetLocalPosition().x, a->GetLocalPosition().y, a->GetLocalPosition().z);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::F))
	{
		printf("b : Local %f %f %f\n", b->GetLocalPosition().x, b->GetLocalPosition().y, b->GetLocalPosition().z);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::Z))
	{
		printf("SetParent\n");
		b->SetParent(a);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::X))
	{
		printf("RemoveParent\n");
		b->RemoveParent();
	}
}