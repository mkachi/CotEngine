#include "DemoScene.h"
/*
using namespace Cot;

bool DemoScene::Init()
{
	a = new Entity("a");
	a->SetPosition(Vec3(10.0f, 0));
	this->AddEntity(a);

	b = new Entity("b");
	b->SetPosition(Vec3(0, 0));
	this->AddEntity(b);

	this->CreateKeyListener();

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

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
		a->SetParent(b);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::X))
	{
		printf("RemoveParent\n");
		b->RemoveParent();
	}
}
*/
#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	PPAP = new Entity("PPAP");
	PPAP->AddComponent<SpriteRenderer>()->Init("Circle.png");
	PPAP->SetPosition(Vec3(0, 0, 0));
	this->AddEntity(PPAP);

	CAMERA = new Entity("CAMERA");
	CAMERA->SetParent(PPAP);
	CAMERA->SetPosition(Vec3(0, 0, 0));
	CAMERA->AddComponent<SpriteRenderer>()->Init("Circle.png");
	this->AddEntity(CAMERA);

	this->CreateKeyListener();

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (this->GetKeyListener()->IsKeyStay(KeyCode::D))
	{
		nowX++;
		printf("%d %d\n", nowX, nowY);
	}
	PPAP->SetPosition(Vec3(nowX, nowY, 0));

	if (this->GetKeyListener()->IsKeyDown(KeyCode::A))
	{
		printf("%f %f %f\n", CAMERA->GetPosition().x, CAMERA->GetPosition().y, CAMERA->GetPosition().z);
	}

	if (this->GetKeyListener()->IsKeyDown(KeyCode::SpaceBar))
	{
		CAMERA->SetPosition(Vec3(0, 300, 0));
	}

}