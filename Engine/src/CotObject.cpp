#include "base/object/CotObject.h"

namespace Cot
{
	Object::Object()
	{	}

	Object::~Object()
	{	}

	void Object::SetPosition(const Vec3& position)
	{
		_position = position;
	}

	void Object::SetPositionX(float x)
	{
		_position.x = x;
	}

	void Object::SetPositionY(float y)
	{
		_position.y = y;
	}

	void Object::SetPositionZ(float z)
	{
		_position.z = z;
	}

	void Object::SetRotate(const Vec3& rotate)
	{
		_rotate = rotate;
	}

	void Object::SetRotateX(float x)
	{
		_rotate.x = x;
	}

	void Object::SetRotateY(float y)
	{
		_rotate.y = y;
	}

	void Object::SetRotateZ(float z)
	{
		_rotate.z = z;
	}

	void Object::SetScale(const Vec3& scale)
	{
		_scale = scale;
	}

	void Object::SetScaleX(float x)
	{
		_scale.x = x;
	}

	void Object::SetScaleY(float y)
	{
		_scale.y = y;
	}

	void Object::SetScaleZ(float z)
	{
		_scale.z = z;
	}

	void Object::SetActive(bool active)
	{
		_active = active;
	}

	void Object::Update()
	{
		if (!_active)
		{
			return;
		}
		Node::Update();
	}
}