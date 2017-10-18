#include "base/CotScene.h"
#include "base/CotEntity.h"

namespace Cot
{
	Scene::Scene()
	{	}

	Scene::~Scene()
	{	
		for (auto& entity : _entitys)
		{
			SafeDelete(entity);
		}
	}

	void Scene::SetGraphicsDevice(IGraphics* graphics)
	{
		this->graphics = graphics;
	}

	void Scene::Update(Time& time)
	{
		for (auto& entity : _entitys)
		{
			entity->Update(time);
		}
	}

	void Scene::Start()
	{
		for (auto& entity : _entitys)
		{
			entity->ComponentStart();
		}
	}

	void Scene::AddEntity(Entity* entity)
	{
		_entitys.push_back(entity);
	}
}