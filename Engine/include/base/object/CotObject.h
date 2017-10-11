#pragma once

#include "base/CotNode.h"

namespace Cot
{
	class COT_API Object
		: public Node
	{
	protected:
		bool _active;

	public:
		Object();
		virtual ~Object();

		void SetActive(bool active);
		bool IsActive() { return _active; }

		virtual void Update();

	};
}