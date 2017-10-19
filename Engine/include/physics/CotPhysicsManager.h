#pragma once

#include "CotPhysics.h"
#include "component/CotBoxCollider.h"
#include "component/CotCircleCollider.h"

namespace Cot
{
	class COT_API PhysicsManager final
	{
		COT_SINGLETON_H(PhysicsManager);
	private:
		std::vector<ICollider*> _colliders;

	public:
		void Add(ICollider* coll);
		void Update(Time& time);

	};
}