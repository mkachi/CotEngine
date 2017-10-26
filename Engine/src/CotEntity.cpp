#include "base/CotEntity.h"
#include "component/CotIComponent.h"

namespace Cot
{
	Entity::Entity(const string& name)
		: _name(name)
		, _broadCastProtocol(nullptr)
		, _active(true)
		, _world(Mat4::Identity)
		, _dirty(true)
		, _localPosition(Vec3::Zero)
		, _localRotate(Vec3::Zero)
		, _localScale(Vec3::One)
		, _parent(nullptr)
	{	}

	Entity::~Entity()
	{	
		for (int i = 0; i < _components.size(); ++i)
		{
			IComponent* temp = _components[i].second;
			SafeDelete(temp);
		}
		_components.clear();
		SafeDelete(_broadCastProtocol);
	}

	void Entity::ComponentStart()
	{
		for (int i = 0; i < _components.size(); ++i)
		{
			IComponent* temp = _components[i].second;
			if (temp->IsEnable())
			{
				temp->Start();
			}
		}
	}

	void Entity::CreateBroadCastProtocol()
	{
		if (_broadCastProtocol == nullptr)
		{
			_broadCastProtocol = new BroadCastProtocol();
		}
	}

	void Entity::AddBroadCastListener(const string& name, const std::function<void()>& function)
	{
		_broadCastProtocol->Add(name, function);
	}

	void Entity::SendMsg(const string& function)
	{
		COT_ASSERT(_broadCastProtocol == nullptr, "_broadCastProtocol is nullptr.");
		_broadCastProtocol->Invoke(function);
	}

	void Entity::BroadCastMsg(const string& function)
	{
		COT_ASSERT(_broadCastProtocol == nullptr, "_broadCastProtocol is nullptr.");
		_broadCastProtocol->Invoke(function);
		for (auto& child : _children)
		{
			child->BroadCastMsg(function);
		}
	}

	void Entity::SetParent(Entity* parent)
	{
		_parent = parent;
		_parent->_children.push_back(this);

		SetPosition(_localPosition);
		SetRotateAxis(_localRotate.x, Vec3(1.0f, 0.0f, 0.0f));
		SetRotateAxis(_localRotate.y, Vec3(0.0f, 1.0f, 0.0f));
		SetRotateAxis(_localRotate.z, Vec3(0.0f, 0.0f, 1.0f));
		SetScale(_localScale);
	}

	void Entity::AddChild(Entity* child)
	{
		child->_parent = this;
		_children.push_back(child);

		child->SetPosition(child->_localPosition);
		child->SetPosition(child->_localPosition);
		child->SetRotateAxis(child->_localRotate.x, Vec3(1.0f, 0.0f, 0.0f));
		child->SetRotateAxis(child->_localRotate.y, Vec3(0.0f, 1.0f, 0.0f));
		child->SetRotateAxis(child->_localRotate.z, Vec3(0.0f, 0.0f, 1.0f));
		child->SetScale(child->_localScale);
	}

	void Entity::RemoveParent()
	{
		if (_parent != nullptr)
		{
			_dirty = true;
			_localPosition += _parent->_localPosition;
			_localRotate += _parent->_localRotate;
			_localScale *= _parent->_localScale;
			_parent = nullptr;
		}
	}

	void Entity::RemoveChild(Entity* child)
	{
		if (_children.empty())
		{
			return;
		}
		_children.erase(std::find(_children.cbegin(), _children.cend(), child));

		child->_dirty = true;
		child->_localPosition += _localPosition;
		child->_localRotate += _localRotate;
		child->_localScale *= _localScale;
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

		(*find)->_dirty = true;
		(*find)->_localPosition += _localPosition;
		(*find)->_localRotate += _localRotate;
		(*find)->_localScale *= _localScale;
	}

	void Entity::RemoveAllChild()
	{
		for (auto& child : _children)
		{
			child->_dirty = true;
			child->_localPosition += _localPosition;
			child->_localRotate += _localRotate;
			child->_localScale *= _localScale;
		}
		_children.clear();
	}

	void Entity::SetName(const string& name)
	{
		_name = name;
	}

	void Entity::ResetTransform()
	{
		_localPosition = Vec3::Zero;
		_localRotate = Vec3::Zero;
		_localScale = Vec3::One;
		_dirty = true;
	}

	void Entity::SetPosition(const Vec3& position)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localPosition = position - _parent->_localPosition;
			return;
		}
		_localPosition = position;
	}

	void Entity::SetPositionX(float x)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localPosition.x = x - _parent->_localPosition.x;
			return;
		}
		_localPosition.x = x;
	}

	void Entity::SetPositionY(float y)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localPosition.y = y - _parent->_localPosition.y;
			return;
		}
		_localPosition.y = y;
	}

	void Entity::SetPositionZ(float z)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localPosition.z = z - _parent->_localPosition.z;
			return;
		}
		_localPosition.z = z;
	}

	Vec3 Entity::GetPosition()
	{
		if (_parent != nullptr)
		{
			return _localPosition + _parent->_localPosition;
		}
		return _localPosition;
	}

	void Entity::SetRotateAxis(float deg, const Vec3& axis)
	{
		_dirty = true;
		float r = deg;
		if (r < 0.0f)
		{
			r += 360.0f;
		}

		if (_parent != nullptr)
		{
			_localRotate = (axis * r) - _parent->_localRotate;
			return;
		}
		_localRotate = axis * r;
	}

	Vec3 Entity::GetRotate()
	{
		if (_parent != nullptr)
		{
			return _localRotate + _parent->_localRotate;
		}
		return _localRotate;
	}

	void Entity::SetScale(const Vec3& scale)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localScale = scale / _parent->_localScale;
			return;
		}
		_localScale = scale;
	}

	void Entity::SetScaleX(float x)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localScale.x = x / _parent->_localScale.x;
			return;
		}
		_localScale.x = x;
	}

	void Entity::SetScaleY(float y)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localScale.y = y / _parent->_localScale.y;
			return;
		}
		_localScale.y = y;
	}

	void Entity::SetScaleZ(float z)
	{
		_dirty = true;
		if (_parent != nullptr)
		{
			_localScale.z = z / _parent->_localScale.z;
			return;
		}
		_localScale.z = z;
	}

	Vec3 Entity::GetScale()
	{
		if (_parent != nullptr)
		{
			return _localScale * _parent->_localScale;
		}
		return _localScale;
	}

	void Entity::SetLocalPosition(const Vec3& position)
	{
		_dirty = true;
		_localPosition = position;
	}

	void Entity::SetLocalPositionX(float x)
	{
		_dirty = true;
		_localPosition.x = x;
	}

	void Entity::SetLocalPositionY(float y)
	{
		_dirty = true;
		_localPosition.y = y;
	}

	void Entity::SetLocalPositionZ(float z)
	{
		_dirty = true;
		_localPosition.z = z;
	}

	Vec3 Entity::GetLocalPosition()
	{
		return _localPosition;
	}

	void Entity::SetLocalRotateAxis(float deg, const Vec3& axis)
	{
		_dirty = true;
		float r = deg;
		if (r < 0.0f)
		{
			r += 360.0f;
		}
		_localRotate = axis * r;
	}

	Vec3 Entity::GetLocalRotate()
	{
		return _localRotate;
	}

	void Entity::SetLocalScale(const Vec3& scale)
	{
		_dirty = true;
		_localScale = scale;
	}

	void Entity::SetLocalScaleX(float x)
	{
		_dirty = true;
		_localScale.x = x;
	}

	void Entity::SetLocalScaleY(float y)
	{
		_dirty = true;
		_localScale.y = y;
	}

	void Entity::SetLocalScaleZ(float z)
	{
		_dirty = true;
		_localScale.z = z;
	}

	Vec3 Entity::GetLocalScale()
	{
		return _localScale;
	}

	Mat4 Entity::GetWorldMatrix()
	{
		if (_dirty)
		{
			for (int i = 0; i < _children.size(); ++i)
			{
				_children[i]->SetDirty(true);
			}

			_world = Mat4::Identity;

			if (_parent != nullptr)
			{
				_world = _parent->GetWorldMatrix();
			}

			_world *= Mat4::Translate(_localPosition);
			Quaternion quaternion = Quaternion::Identity;
			_world *= Mat4::Rotate(_localRotate.x, Vec3(1.0f, 0.0f, 0.0f));
			_world *= Mat4::Rotate(_localRotate.y, Vec3(0.0f, 1.0f, 0.0f));
			_world *= Mat4::Rotate(_localRotate.z, Vec3(0.0f, 0.0f, 1.0f));
			_world *= Mat4::Scale(_localScale);

			_dirty = false;
		}
		return _world;
	}

	void Entity::SetDirty(bool value)
	{
		_dirty = value;
	}

	void Entity::SetActive(bool active)
	{
		_active = active;
	}

	void Entity::Update(Time& time)
	{	
		if (!_active)
		{
			return;
		}

		for (auto& child : _children)
		{
			child->Update(time);
		}

		for (int i = 0; i < _components.size(); ++i)
		{
			IComponent* temp = _components[i].second;
			if (temp->IsEnable())
			{
				temp->Update(time);
			}
		}
	}
}