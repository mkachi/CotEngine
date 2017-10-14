#pragma once

#include "CotTime.h"

namespace Cot
{
	class Entity;
	class COT_API Scene
	{
	private:
		std::vector<Entity*> _entitys;

	protected:
		Scene();

	public:
		virtual ~Scene();

		virtual bool Init() = 0;
		virtual void Update(Time& time);

		void Start();
		void AddEntity(Entity* entity);

	};
}