#pragma once

#include "CotTime.h"

namespace Cot
{
	class COT_API Scene
	{
	private:
		std::vector<class Entity*> _entitys;

	protected:
		Scene();

	public:
		virtual ~Scene();

		virtual bool Init() = 0;
		virtual void Update(Time& time);

		void AddEntity(Entity* entity);

	};
}