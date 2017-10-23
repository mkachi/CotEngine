#pragma once

#include "CotBroadCastProtocol.h"
#include "CotTime.h"
#include "CotVectorMap.hpp"
#include "math/CotMath.h"

namespace Cot
{
	class IComponent;
	class COT_API Entity
	{
	protected:
		string		_name;
		bool		_active;

		Mat4		_world;
		bool		_dirty;

		Vec3		_localPosition;
		Vec3		_localRotate;
		Vec3		_localScale;
		Entity*		_parent;

		std::vector<Entity*> _children;
		BroadCastProtocol*	 _broadCastProtocol;
		MultiVectorMap<string, IComponent*> _components;

	public:
		Entity() = delete;
		Entity(const string& name);
		virtual ~Entity();

		void ComponentStart();

		template <typename T>
		T* AddComponent()
		{
			T* result = new T();
			result->SetOwner(this);
			result->OnEnable();
			result->Awake();
			_components.add(result->GetType(), result);
			return result;
		}

		template <typename T>
		void RemoveComponent()
		{
			string key = ComponentType<T>::GetType();
			T* temp = static_cast<T*>(_components.find(key));
			_components.remove(key);
			SafeDelete(temp);
		}

		template <typename T>
		T* GetComponent()
		{
			string key = ComponentType<T>::GetType();
			return static_cast<T*>(_components.find(key));
		}

		template <typename T>
		inline std::vector<T*> GetComponents()
		{
			string key = ComponentType<T>::GetType();
			return _components.finds<T*>(key);
		}

		MultiVectorMap<string, IComponent*>& GetComponentMap() { return _components; }

		void CreateBroadCastProtocol();
		void AddBroadCastListener(const string& name, const std::function<void()>& function);
		void SendMsg(const string& function);
		void BroadCastMsg(const string& function);

		void AddChild(Entity* child);
		std::vector<Entity*>& GetChildren() { return _children; }

		void RemoveParent();
		void RemoveChild(Entity* child);
		void RemoveChildByName(const string& name);
		void RemoveAllChild();

		void SetName(const string& name);
		string GetName() { return _name; }

		void SetParent(Entity* parent);
		Entity* GetParent() { return _parent; }

		void ResetTransform();

		void SetPosition(const Vec3& position);
		void SetPositionX(float x);
		void SetPositionY(float y);
		void SetPositionZ(float z);
		Vec3 GetPosition();

		void SetRotateAxis(float deg, const Vec3& axis);
		Vec3 GetRotate();

		void SetScale(const Vec3& scale);
		void SetScaleX(float x);
		void SetScaleY(float y);
		void SetScaleZ(float z);
		Vec3 GetScale();

		void SetLocalPosition(const Vec3& position);
		void SetLocalPositionX(float x);
		void SetLocalPositionY(float y);
		void SetLocalPositionZ(float z);
		Vec3 GetLocalPosition();

		void SetLocalRotateAxis(float deg, const Vec3& axis);
		Vec3 GetLocalRotate();

		void SetLocalScale(const Vec3& scale);
		void SetLocalScaleX(float x);
		void SetLocalScaleY(float y);
		void SetLocalScaleZ(float z);
		Vec3 GetLocalScale();

		Mat4 GetWorldMatrix();
		
		void SetDirty(bool value);
		bool IsDirty() { return _dirty; }

		void SetActive(bool active);
		bool IsActive() { return _active; }

		virtual void Update(Time& time);

	};
}