#include "DemoScene.h"

using namespace Cot;

bool DemoScene::Init()
{
	a = new Entity("a");
	FontRenderer* fontRenderer1 = a->AddComponent<FontRenderer>()->Init("Arial.ttf", "Test", 60);
	fontRenderer1->SetDepth(1);
	a->SetPosition(Vec3(0.0f, 0.0f));
	this->AddEntity(a);

	Entity* c = new Entity("a");
	SpriteRenderer* spriteRenderer = c->AddComponent<SpriteRenderer>()->Init("Circle.png");
	spriteRenderer->SetDepth(0);
	c->SetPosition(Vec3(0.0f, 0.0f));
	this->AddEntity(c);

	Entity* b = new Entity("a");
	FontRenderer* fontRenderer2 = b->AddComponent<FontRenderer>()->Init("Arial.ttf", "Ang", 60);
	fontRenderer2->SetDepth(-1);
	fontRenderer2->SetColor(Color(1.0f, 0.0f, 0.0f));
	b->SetPosition(Vec3(40.0f, 0.0f));
	this->AddEntity(b);

	return true;
}

void DemoScene::Update(Cot::Time& time)
{
	Scene::Update(time);
}