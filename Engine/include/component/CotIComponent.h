#pragma once

#include "base/CotTime.h"

namespace Cot
{
	class COT_API IComponent
	{
		COT_INTERFACE(IComponent);
	protected:
		string _type;

	public:
		virtual void OnEnable()			{}
		virtual void Reset()			{}
		virtual void Awake()			{}
		virtual void Start()			{}
		virtual void FixedUpdate()		{}
		virtual void Update(Time& time)	{}
		virtual void LateUpdate()		{}
		virtual void OnDisable()		{}
		virtual void OnDestroy()		{}
	};
}