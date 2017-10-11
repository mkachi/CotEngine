#include "base/CotSceneManager.h"
#include <Windows.h>

namespace Cot
{
	COT_SINGLETON_CPP(SceneManager);

	void SceneManager::DestroyAllScene()
	{
		for (auto& scene : _scenes)
		{
			SafeDelete(scene);
		}
		_scenes.clear();
	}

	void SceneManager::LoadScene(IScene* scene)
	{
		if (scene != nullptr)
		{
			DestroyAllScene();
			if (!scene->Init())
			{
				MessageBox(NULL, L"Scene init failed.", L"Error", MB_OK);
				return;
			}
			_scenes.push_back(scene);
		}
	}

	void SceneManager::AddScene(IScene* scene)
	{
		_scenes.push_back(scene);
	}

	void SceneManager::Update(Time& time)
	{
		for (auto& scene : _scenes)
		{
			scene->Update(time);
		}
	}
}