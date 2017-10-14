#include "base/CotSceneManager.h"

#define WIN32_LEAN_AND_MEAN
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

	void SceneManager::LoadScene(Scene* scene)
	{
		if (scene != nullptr)
		{
			DestroyAllScene();
			if (!scene->Init())
			{
				MessageBox(NULL, L"Scene init failed.", L"Error", MB_OK);
				return;
			}
			scene->Start();
			_scenes.push_back(scene);
		}
	}

	void SceneManager::AddScene(Scene* scene)
	{
		scene->Start();
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