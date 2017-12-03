#include "base/CotSceneManager.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Cot
{
	COT_SINGLETON_CPP(SceneManager);

	void SceneManager::DestroyAllScene()
	{
		for (int i = 0; i < _scenes.size(); ++i)
		{
			SafeDelete(_scenes[i]);
		}
		_scenes.clear();
	}

	void SceneManager::SetGraphicsDevice(IGraphics* graphics)
	{
		_graphics = graphics;
	}

	void SceneManager::LoadScene(Scene* scene)
	{
		if (scene != nullptr)
		{
			DestroyAllScene();
			scene->SetGraphicsDevice(_graphics);
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
		scene->SetGraphicsDevice(_graphics);
		if (!scene->Init())
		{
			MessageBox(NULL, L"Scene init failed.", L"Error", MB_OK);
			return;
		}
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