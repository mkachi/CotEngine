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
	scroll->SetPosition(Vec2(1280.0f * 0.5f, 720.0f * 0.5f));
	this->AddEntity(scroll);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyDown(KeyCode::A))
	{
		scroll->GetComponent<ScrollBar>()->SetValue(0.5f);
	}
}