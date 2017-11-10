#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	button = new Entity("Button");
	button->AddComponent<SpriteRenderer>()->Init("tile_grass.png");
	Button* buttonEvent = button->AddComponent<Button>()->Init(Color(1.0f, 0.0f, 0.0f));
	prograssBar = button->AddComponent<PrograssBar>();
	prograssBar->SetValue(0.0f);
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

	if (IsKeyStay(KeyCode::Q))
	{
		prograssBar->SetValue(prograssBar->GetValue() + time.GetDeltaTime());
	}

	if (IsKeyStay(KeyCode::W))
	{
		prograssBar->SetValue(prograssBar->GetValue() - time.GetDeltaTime());
	}
}