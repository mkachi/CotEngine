#pragma once

#include "CotTime.h"

namespace Cot
{
	class COT_API IScene
	{
		COT_INTERFACE(IScene);
	public:
		virtual bool Init() = 0;
		virtual void Update(Time& time) = 0;

	};
}