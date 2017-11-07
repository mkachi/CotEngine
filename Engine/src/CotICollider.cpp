#include "component/CotICollider.h"

namespace Cot
{
	void ICollider::SetEnter(bool enter)
	{
		_enter = enter;
	}

	void ICollider::Call(Entity* entity)
	{
		for (auto& component : GetOwner()->GetComponentMap())
		{
			component.second->OnCollision(entity);
		}
	}
}