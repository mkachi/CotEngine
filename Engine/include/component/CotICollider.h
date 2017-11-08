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
		void SetEnter(bool enter) { _enter = enter; }
		bool IsEnter() { return _enter; }

		Type GetCollType() { return _collType; }

	};
}