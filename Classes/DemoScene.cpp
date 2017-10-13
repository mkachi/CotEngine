#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	Entity* entity = new Entity("Test");
	entity->CreateBroadCastProtocol();
	entity->AddBroadCastListener(COT_BROAD_CAST(DemoScene::Test));

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}