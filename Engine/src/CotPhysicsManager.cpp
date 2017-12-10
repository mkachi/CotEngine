#include "physics/CotPhysicsManager.h"

namespace Cot
{
	COT_SINGLETON_CPP(PhysicsManager);

	void PhysicsManager::Add(ICollider* coll)
	{
		_colliders.push_back(coll);
	}

	void PhysicsManager::Update(Time& time)
	{
		for (uint i = 0; i < _colliders.size(); ++i)
		{
			for (uint j = 0; j < _colliders.size(); ++j)
			{
				if (i == j)
				{
					continue;
				}

				// Box vs Box
				if (_colliders[i]->GetCollType() == ICollider::Type::Box && 
					_colliders[j]->GetCollType() == ICollider::Type::Box)
				{
					if (IntersectRect(
						static_cast<BoxCollider*>(_colliders[i])->GetRect(),
						static_cast<BoxCollider*>(_colliders[j])->GetRect()))
					{
						_colliders[i]->SetTarget(_colliders[j]->GetOwner());
						_colliders[j]->SetTarget(_colliders[i]->GetOwner());

						_colliders[i]->SetEnter(true);
						_colliders[j]->SetEnter(true);
					}
					else
					{
						_colliders[i]->SetEnter(false);
						_colliders[j]->SetEnter(false);
					}
				}

				// Circle vs Circle
				else if (_colliders[i]->GetCollType() == ICollider::Type::Circle &&
					_colliders[j]->GetCollType() == ICollider::Type::Circle)
				{
					if (IntersectCircle(
						static_cast<CircleCollider*>(_colliders[i])->GetCircle(),
						static_cast<CircleCollider*>(_colliders[j])->GetCircle()))
					{
						_colliders[i]->SetTarget(_colliders[j]->GetOwner());
						_colliders[j]->SetTarget(_colliders[i]->GetOwner());

						_colliders[i]->SetEnter(true);
						_colliders[j]->SetEnter(true);
					}
					else
					{
						_colliders[i]->SetEnter(false);
						_colliders[j]->SetEnter(false);
					}
				}

				// Circle vs Rect
				else if (_colliders[i]->GetCollType() == ICollider::Type::Box &&
					_colliders[j]->GetCollType() == ICollider::Type::Circle)
				{
					if (IntersectRectCircle(
						static_cast<BoxCollider*>(_colliders[i])->GetRect(),
						static_cast<CircleCollider*>(_colliders[j])->GetCircle()))
					{
						_colliders[i]->SetTarget(_colliders[j]->GetOwner());
						_colliders[j]->SetTarget(_colliders[i]->GetOwner());

						_colliders[i]->SetEnter(true);
						_colliders[j]->SetEnter(true);
					}
					else
					{
						_colliders[i]->SetEnter(false);
						_colliders[j]->SetEnter(false);
					}
				}
			}
		}
		_colliders.clear();
	}
}