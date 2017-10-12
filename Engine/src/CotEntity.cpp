#include "base/CotEntity.h"

namespace Cot
{
	Entity::Entity(const string& name)
		: _name(name)
	{	}

	Entity::~Entity()
	{	
		if (_parent != nullptr)
		{
			_parent->RemoveChild(this);
		}
		RemoveAllChild();
		SafeDelete(_broadCastProtocol);
	}

	void Entity::CreateBroadCastProtocol()
	{
		if (_broadCastProtocol == nullptr)
		{
			_broadCastProtocol = new BroadCastProtocol();
		}
	}

	void Entity::SendMessage(const string& function)
	{
		COT_ASSERT(_broadCastProtocol == nullptr, "_broadCastProtocol is nullptr.");
		_broadCastProtocol->Invoke(function);
	}

	void Entity::BroadCastMessage(const string& function)
	{
		COT_ASSERT(_broadCastProtocol == nullptr, "_broadCastProtocol is nullptr.");
		_broadCastProtocol->Invoke(function);
		for (auto& child : _children)
		{
			child->BroadCastMessage(function);
		}
	}

	void Entity::SetParent(Entity* parent)
	{
		_parent = parent;
	}

	void Entity::AddChild(Entity* child)
	{
		child->SetParent(this);
		_children.push_back(child);
	}

	void Entity::RemoveChild(Entity* child)
	{
		_children.erase(std::find(_children.cbegin(), _children.cend(), child));
	}

	void Entity::RemoveChildByName(const string& name)
	{
		std::vector<Entity*>::const_iterator find;
		for (auto iter = _children.cbegin(); iter != _children.cend(); ++iter)
		{
			if ((*iter)->GetName() == name)
			{
				find = iter;
				break;
			}
		}
		_children.erase(find);
	}

	void Entity::RemoveAllChild()
	{
		for (auto& child : _children)
		{
			SafeDelete(child);
		}
	}

	void Entity::SetName(const string& name)
	{
		_name = name;
	}

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

	void Entity::SetRotateAxis(float deg, const Vec3& axis)
	{
		float r = deg;
		if (r < 0.0f)
		{
			r += 360.0f;
		}
		_rotate = axis * r;
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

	void Entity::SetLocalPosition(const Vec3& position)
	{
		if (_parent != nullptr)
		{
			_position = position + _parent->_position;
			return;
		}
		_position = position;
	}

	void Entity::SetLocalPositionX(float x)
	{
		if (_parent != nullptr)
		{
			_position.x = x + _parent->_position.x;
			return;
		}
		_position.x = x;
	}

	void Entity::SetLocalPositionY(float y)
	{
		if (_parent != nullptr)
		{
			_position.y = y + _parent->_position.y;
			return;
		}
		_position.y = y;
	}

	void Entity::SetLocalPositionZ(float z)
	{
		if (_parent != nullptr)
		{
			_position.z = z + _parent->_position.z;
			return;
		}
		_position.z = z;
	}

	Vec3 Entity::GetLocalPosition()
	{
		if (_parent != nullptr)
		{
			return _position - _parent->_position;
			return;
		}
		return _position;
	}

	void Entity::SetLocalRotateAxis(float deg, const Vec3& axis)
	{
		float r = deg;
		if (r < 0.0f)
		{
			r += 360.0f;
		}

		if (_parent != nullptr)
		{
			_rotate = _parent->_rotate + (axis * r);
			return;
		}
		_rotate = axis * r;
	}

	Vec3 Entity::GetLocalRotate()
	{
		if (_parent != nullptr)
		{
			return _rotate - _parent->_rotate;
		}
		return _position;
	}

	void Entity::SetLocalScale(const Vec3& scale)
	{
		if (_parent != nullptr)
		{
			_scale = _parent->_scale * scale;
			return;
		}
		_scale = scale;
	}

	void Entity::SetLocalScaleX(float x)
	{
		if (_parent != nullptr)
		{
			_scale.x = _parent->_scale.x * x;
			return;
		}
		_scale.x = x;
	}

	void Entity::SetLocalScaleY(float y)
	{
		if (_parent != nullptr)
		{
			_scale.y = _parent->_scale.y * y;
			return;
		}
		_scale.y = y;
	}

	void Entity::SetLocalScaleZ(float z)
	{
		if (_parent != nullptr)
		{
			_scale.z = _parent->_scale.z * z;
			return;
		}
		_scale.z = z;
	}

	Vec3 Entity::GetLocalScale()
	{
		if (_parent != nullptr)
		{
			if (_parent->_scale.x <= 0.0f || 
				_parent->_scale.y <= 0.0f || 
				_parent->_scale.z <= 0.0f)
			{
				return Vec3::Zero;
			}
			return _scale / _parent->_scale;
		}
		return _scale;
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

		for (auto& child : _children)
		{
			child->Update();
		}
	}
}