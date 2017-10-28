#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	a = new Entity("a");
	a->AddComponent<SpriteRenderer>()->Init("Circle.png");
	Animation* animation = a->AddComponent<Animation>()->Init({
		AnimationData("Circle.png"),
		AnimationData("atlas.caif", "stoneLeft"),
		AnimationData("atlas.caif", "stoneMid"),
		AnimationData("atlas.caif", "stoneRight"),
		AnimationData("atlas.caif", "stoneWall"),
		AnimationData("atlas.caif", "tochLit"),
		AnimationData("atlas.caif", "tochLit2"),
		AnimationData("atlas.caif", "torch"),
		AnimationData("atlas.caif", "window"),
	}, 0.1f);
	animation->Play();
	animation->SetReverse(true);
	a->SetPosition(Vec3(400.0f, 300.0f));
	this->AddEntity(a);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);

	if (IsKeyDown(KeyCode::A))
	{
		a->GetComponent<SpriteRenderer>()->SetTexture("Test.png");
	}

	if (IsKeyDown(KeyCode::S))
	{
		a->GetComponent<SpriteRenderer>()->SetTexture("atlas.caif", "stoneLeft");
	}

	if (IsKeyDown(KeyCode::D))
	{
		a->GetComponent<SpriteRenderer>()->SetTexture("atlas.caif", "window");
	}
}