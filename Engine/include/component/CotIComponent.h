#pragma once

#include "base/CotEntity.h"
#include "base/CotNode.h"

namespace Cot
{
	class COT_API IComponent
		: public Node
	{
		COT_INTERFACE(IComponent);
	protected:
		string		_type;
		Entity*		_owner;
		bool		_enable;

	public:
		string GetType() { return _type; }

		void SetOwner(Entity* owner);
		Entity* GetOwner() { return _owner; }

		void SetEnable(bool enable);
		bool IsEnable() { return _enable; }

		virtual void OnEnable()			{}
		virtual void Reset()			{}
		virtual void Awake()			{}
		virtual void Start()			{}
		virtual void Update(Time& time)	{}
		virtual void OnDisable()		{}
		virtual void OnDestroy()		{}

		virtual void OnTriggerEnter(Entity* entity) {}
		virtual void OnTriggerStay(Entity* entity)	{}
		virtual void OnTriggerExit(Entity* entity)	{}

	};
}