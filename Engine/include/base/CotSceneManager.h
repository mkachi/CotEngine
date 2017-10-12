#pragma once

#include "CotScene.h"
#include <stack>

namespace Cot
{
	class COT_API SceneManager final
	{
		COT_SINGLETON_H(SceneManager);
	private:
		std::vector<Scene*> _scenes;

	public:
		void LoadScene(Scene* scene);
		void AddScene(Scene* scene);
		void Update(Time& time);

		void DestroyAllScene();

	};
}