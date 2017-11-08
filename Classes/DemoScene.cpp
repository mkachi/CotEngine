#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	button = new Entity("Button");
	button->AddComponent<SpriteRenderer>()->Init("tile.png");
	Button* buttonEvent = button->AddComponent<Button>()->Init(Color(1.0f, 0.0f, 0.0f));
	button->SetPosition(Vec2(1280.0f / 2.0f, 720.0f / 2.0f));
	this->AddEntity(button);

	buttonEvent->AddButtonDown([]()		{	printf("Down\n");	});
	buttonEvent->AddButtonUp([]()		{	printf("Up\n");		});
	buttonEvent->AddButtonClick([]()	{	printf("Click\n");	});

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}