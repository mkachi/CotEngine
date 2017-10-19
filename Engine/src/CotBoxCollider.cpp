#include "component/CotBoxCollider.h"
#include "component/CotSpriteRenderer.h"
#include "physics/CotPhysicsManager.h"

namespace Cot
{
	BoxCollider* BoxCollider::Init(const Size& size)
	{
		_size = size;
		return this;
	}

	void BoxCollider::Reset()
	{
		_collType = Type::Box;
	}

	void BoxCollider::Update(Time& time)
	{
		PhysicsManager::GetInstance().Add(this);
	}

	void BoxCollider::SetSpriteSize()
	{
		SpriteRenderer* renderer = GetOwner()->GetComponent<SpriteRenderer>();
		if (renderer != nullptr)
		{
			_size = renderer->GetRect().size;
		}
	}

	void BoxCollider::SetRect(const Size& size)
	{
		_size = size;
	}
}