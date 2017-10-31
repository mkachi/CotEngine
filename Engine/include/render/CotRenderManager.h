#pragma once

#include "base/CotRule.h"
#include "component/CotIRenderComponent.h"

namespace Cot
{
	class COT_API RenderManager final
	{
		COT_SINGLETON_H(RenderManager);
	private:
		std::vector<IRenderComponent*> _renderQ;

	public:
		void Add(IRenderComponent* command);
		void Clear();

		std::vector<IRenderComponent*> GetRenderQ() { return _renderQ; }

	};
}