#include "base/CotEntity.h"

namespace Cot
{
	Entity::Entity()
	{	}

	Entity::~Entity()
	{	}

	void Entity::SetPosition(const Vec3& position)
	{
		_position = position;
	}

	void Entity::SetPositionX(float x)
	{
		_position.x = x;
	}

	void Entity::SetPositionY(float y)
	{
		_position.y = y;
	}

	void Entity::SetPositionZ(float z)
	{
		_position.z = z;
	}

	void Entity::SetRotate(const Vec3& rotate)
	{
		_rotate = rotate;
	}

	void Entity::SetRotateX(float x)
	{
		_rotate.x = x;
	}

	void Entity::SetRotateY(float y)
	{
		_rotate.y = y;
	}

	void Entity::SetRotateZ(float z)
	{
		_rotate.z = z;
	}

	void Entity::SetScale(const Vec3& scale)
	{
		_scale = scale;
	}

	void Entity::SetScaleX(float x)
	{
		_scale.x = x;
	}

	void Entity::SetScaleY(float y)
	{
		_scale.y = y;
	}

	void Entity::SetScaleZ(float z)
	{
		_scale.z = z;
	}

	void Entity::SetActive(bool active)
	{
		_active = active;
	}

	void Entity::Update()
	{
		if (!_active)
		{
			return;
		}
		Node::Update();
	}
}