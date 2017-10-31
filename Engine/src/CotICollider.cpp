#include "component/CotICollider.h"

namespace Cot
{
	void ICollider::Enter(Entity* entity)
	{
		if (!_enter && _owner->IsDirty())
		{
			_enter = true;
			for (auto& component : GetOwner()->GetComponentMap())
			{
				component.second->OnTriggerEnter(entity);
			}
		}
	}

	void ICollider::Stay(Entity* entity)
	{
		if (_enter)
		{
			for (auto& component : GetOwner()->GetComponentMap())
			{
				component.second->OnTriggerStay(entity);
			}
		}
	}

	void ICollider::Exit(Entity* entity)
	{
		if (_enter)
		{
			_enter = false;
			for (auto& component : GetOwner()->GetComponentMap())
			{
				component.second->OnTriggerExit(entity);
			}
		}
	}
}