#pragma once

#include "CotIScene.h"
#include <stack>

namespace Cot
{
	class COT_API SceneManager final
	{
		COT_SINGLETON_H(SceneManager);
	private:
		std::vector<IScene*> _scenes;

	public:
		void LoadScene(IScene* scene);
		void AddScene(IScene* scene);
		void Update(Time& time);

		void DestroyAllScene();

	};
}