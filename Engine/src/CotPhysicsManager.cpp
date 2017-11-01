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

				if (_colliders[i]->GetCollType() == ICollider::Type::Box &&
					_colliders[j]->GetCollType() == ICollider::Type::Box)
				{
					if (IntersectRect(
						static_cast<BoxCollider*>(_colliders[i])->GetRect(),
						static_cast<BoxCollider*>(_colliders[j])->GetRect()))
					{
						_colliders[j]->Enter(_colliders[i]->GetOwner());
						_colliders[j]->Stay(_colliders[i]->GetOwner());

					//	_colliders[j]->Enter(_colliders[i]->GetOwner());
					//	_colliders[j]->Stay(_colliders[i]->GetOwner());
					}
					else
					{
						_colliders[j]->Exit(_colliders[i]->GetOwner());
					//	_colliders[j]->Exit(_colliders[i]->GetOwner());
					}
				}
				
				/*else if (_colliders[i]->GetCollType() == ICollider::Type::Circle &&
					_colliders[j]->GetCollType() == ICollider::Type::Circle)
				{
					if (IntersectCircle(
						static_cast<CircleCollider*>(_colliders[i])->GetCircle(),
						static_cast<CircleCollider*>(_colliders[j])->GetCircle()))
					{
						_colliders[i]->Enter(_colliders[j]->GetOwner());
						_colliders[i]->Stay(_colliders[j]->GetOwner());

						_colliders[j]->Enter(_colliders[i]->GetOwner());
						_colliders[j]->Stay(_colliders[i]->GetOwner());
					}
					else
					{
						_colliders[i]->Exit(_colliders[j]->GetOwner());
						_colliders[j]->Exit(_colliders[i]->GetOwner());
					}
				}
				
				else if (
					(_colliders[i]->GetCollType() == ICollider::Type::Box &&
					 _colliders[j]->GetCollType() == ICollider::Type::Circle) ||

					(_colliders[i]->GetCollType() == ICollider::Type::Circle &&
					 _colliders[j]->GetCollType() == ICollider::Type::Box))
				{
					if (IntersectRectCircle(
						static_cast<BoxCollider*>(_colliders[i])->GetRect(),
						static_cast<CircleCollider*>(_colliders[j])->GetCircle()))
					{
						_colliders[i]->Enter(_colliders[j]->GetOwner());
						_colliders[i]->Stay(_colliders[j]->GetOwner());

						_colliders[j]->Enter(_colliders[i]->GetOwner());
						_colliders[j]->Stay(_colliders[i]->GetOwner());
					}
					else
					{
						_colliders[i]->Exit(_colliders[j]->GetOwner());
						_colliders[j]->Exit(_colliders[i]->GetOwner());
					}
				}*/
			}
		}
		_colliders.clear();
	}
}