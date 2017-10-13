#pragma once

#include "base/CotRule.h"
#include "component/CotSpriteRenderer.h"

namespace Cot
{
	class COT_API RenderManager final
	{
		COT_SINGLETON_H(RenderManager);
	private:
		std::vector<SpriteRenderer*> _renderQ;

	public:
		void Add(SpriteRenderer* command);
		void Clear();

		std::vector<SpriteRenderer*> GetRenderQ() { return _renderQ; }

	};
}