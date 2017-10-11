#pragma once

#include "CotNode.h"
#include "CotTime.h"

namespace Cot
{
	class COT_API IScene
		: public Node
	{
		COT_INTERFACE(IScene);
	public:
		virtual bool Init() = 0;
		virtual void Update(Time& time) = 0;

	};
}