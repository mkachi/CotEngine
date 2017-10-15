#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	//entity = new Entity("Test");
	//entity->AddComponent<AudioListener>()->Init();
	//entity->AddComponent<SpriteRenderer>()->Init("Test.png");
	//entity->AddComponent<AudioSource>()->Init("Test.wav")->Play();
	//entity->SetPosition(Vec2(400, 300));
	//this->AddEntity(entity);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyDown(KeyCode::A))
	{
		printf("Down A\n");
	}

	if (IsKeyStay(KeyCode::S))
	{
		printf("Pressed S\n");
	}

	if (IsKeyUp(KeyCode::A))
	{
		printf("Up A\n");
	}

	if (IsMouseDown(MouseButton::LButton))
	{
		printf("Down LButton\n");
	}

	if (IsMouseUp(MouseButton::MButton))
	{
		printf("Up MButton\n");
	}

	if (IsMouseStay(MouseButton::RButton))
	{
		printf("Pressed RButton\n");
	}
}