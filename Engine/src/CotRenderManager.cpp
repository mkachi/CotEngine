#include "render/CotRenderManager.h"

namespace Cot
{
	COT_SINGLETON_CPP(RenderManager);

	void RenderManager::Add(SpriteRenderer* command)
	{
		_renderQ.push_back(command);
	}

	void RenderManager::Clear()
	{
		_renderQ.clear();
	}
}