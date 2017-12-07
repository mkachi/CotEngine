#include "base/CotScene.h"
#include "base/CotEntity.h"

namespace Cot
{
	Scene::Scene()
	{	}

	Scene::~Scene()
	{	
		for (int i = 0; i < _entitys.size(); ++i)
		{
			SafeDelete(_entitys[i]);
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

	void Scene::LateUpdate(Time& time)
	{
		for (auto& entity : _entitys)
		{
			entity->LateUpdate(time);
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

	void Scene::RemoveEntity(Entity* entity)
	{
		_entitys.erase(std::find(_entitys.cbegin(), _entitys.cend(), entity));
	}
}