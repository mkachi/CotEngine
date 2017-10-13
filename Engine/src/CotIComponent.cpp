#include "component/CotIComponent.h"

namespace Cot
{
	void IComponent::SetOwner(Entity* owner)
	{
		_owner = owner;
	}

	void IComponent::SetEnable(bool enable)
	{
		_enable = enable;
		if (_enable)
		{
			OnEnable();
		}
		else
		{
			OnDisable();
		}
	}
}