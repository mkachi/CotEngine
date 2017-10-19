#pragma once

#include "CotTime.h"
#include "render/CotIGraphics.h"

namespace Cot
{
	class Entity;
	class COT_API Scene
	{
	private:
		std::vector<Entity*> _entitys;

	protected:
		IGraphics* graphics;
		Scene();

	public:
		virtual ~Scene();

		void SetGraphicsDevice(IGraphics* graphics);

		virtual bool Init() = 0;
		virtual void Update(Time& time);

		void Start();
		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);

	};
}