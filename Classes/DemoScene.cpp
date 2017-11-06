#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	//Root
	root = new Entity("root");
	SpriteRenderer* renderer = root->AddComponent<SpriteRenderer>()->Init("Test.png");
	Button* button = root->AddComponent<Button>()->Init(Color(1.0f, 0.0f, 0.0f));
	root->AddComponent<BoxCollider>()->SetSpriteSize();
	root->SetPosition(Vec3(renderer->GetRect().size.width / 2 + 100.0f, renderer->GetRect().size.height / 2 + 100.0f));
	this->AddEntity(root);

	button->AddButtonDown([]() { printf("Down\n"); });
	button->AddButtonUp([]() { printf("Up\n"); });
	button->AddButtonClick([]() { printf("Click\n"); });

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}