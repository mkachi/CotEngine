#include "asset/CotAssetManager.h"

namespace Cot
{
	COT_SINGLETON_CPP(AssetManager);

	Asset* AssetManager::GetAsset(const string& key)
	{
		if (IsHave(key))
		{
			return _assets[key];
		}
		return nullptr;
	}

	void AssetManager::Add(const string& key, Asset* asset)
	{
		if (!IsHave(key))
		{
			_assets.emplace(std::make_pair(key, asset));
		}
	}

	void AssetManager::Remove(const string& key)
	{
		if (IsHave(key))
		{
			_assets.erase(key);
		}
	}

	bool AssetManager::IsHave(const string& key)
	{
		auto iter = _assets.find(key);
		if (iter != _assets.end())
		{
			return true;
		}
		return false;
	}

	void AssetManager::DestroyAllAssets()
	{
		for (auto& asset : _assets)
		{
			SafeDelete(asset.second);
		}
	}
}