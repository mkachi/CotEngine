#include "render/CotRenderManager.h"

namespace Cot
{
	COT_SINGLETON_CPP(RenderManager);

	void RenderManager::Add(SpriteRenderer* command)
	{
		_renderQ.push_back(command);
	}

	void RenderManager::Remove(SpriteRenderer* command)
	{
		_renderQ.erase(std::find(_renderQ.cbegin(), _renderQ.cend(), command));
	}

	void RenderManager::Clear()
	{
		_renderQ.clear();
	}
}