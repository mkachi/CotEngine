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
		OutputDebugStringA("Down A\n");
	}

	if (IsKeyPressed(KeyCode::B))
	{
		OutputDebugStringA("Pressed B\n");
	}

	if (IsKeyUp(KeyCode::A))
	{
		OutputDebugStringA("Up A\n");
	}

	if (IsMouseDown(KeyCode::MouseLButton))
	{
		OutputDebugStringA("Down LButton\n");
	}

	if (IsMouseUp(KeyCode::MouseMButton))
	{
		OutputDebugStringA("Up MButton\n");
	}

	if (IsMousePressed(KeyCode::MouseRButton))
	{
		OutputDebugStringA("Pressed RButton\n");
	}
}