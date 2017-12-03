#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	Entity* button = new Entity("Button");
	button->AddComponent<SpriteRenderer>()->Init("ScrollButton.png");
	button->AddComponent<Button>()->Init(Color(1.0f, 1.0f, 1.0f, 0.5f));
	this->AddEntity(button);

	scroll = new Entity("Test");
	scroll->AddComponent<ScrollBar>()->Init("ScrollBack.png", button);
	scroll->AddComponent<Mask>()->Init(scroll->GetComponent<ScrollBar>());
	scroll->SetPosition(Vec2(1280.0f * 0.5f, 720.0f * 0.5f));
	this->AddEntity(scroll);

	test = new Entity("Test2");
	test->AddComponent<SpriteRenderer>()->Init("ScrollButton.png");
	this->AddEntity(test);

	scroll->AddChild(test);
	test->SetLocalPosition(Vec3(0.0f, 0.0f, 0.0f));

//	scroll->SetRotateAxis(90.0f, Vec3(0.0f, 1.0f, 0.0f));

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyDown(KeyCode::A))
	{
		scroll->GetComponent<ScrollBar>()->SetValue(0.5f);
	}

	if (IsKeyStay(KeyCode::D))
	{
		test->SetRotateAxis(test->GetRotate().z + 50 * time.GetDeltaTime(), Vec3(0.0f, 0.0f, 1.0f));
	}
}