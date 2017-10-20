#pragma once

#include "CotIComponent.h"
#include "math/CotMath.h"

namespace Cot
{
	Component(ICollider)
	{
		COT_COMPONENT(ICollider);
	public:
		enum class Type
		{
			Box,
			Circle,
			Line,
		};

	protected:
		Type	_collType;
		bool	_enter = false;

	public:
		void Enter(Entity* entity);
		void Stay(Entity* entity);
		void Exit(Entity* entity);

		Type GetCollType() { return _collType; }

	};
}