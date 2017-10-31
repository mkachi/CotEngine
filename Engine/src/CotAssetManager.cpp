#include "asset/CotAssetManager.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

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

	void AssetManager::AddFontCache(const string& fontPath)
	{
		auto iter = _fontCache.find(fontPath);
		if (iter != _fontCache.end())
		{
			return;
		}
		wstring wPath = ToWString(fontPath);
		AddFontResourceEx(wPath.c_str(), FR_PRIVATE, NULL);
		_fontCache.emplace(std::make_pair(fontPath, wPath));
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

		for (auto& font : _fontCache)
		{
			RemoveFontResourceEx(font.second.c_str(), FR_PRIVATE, NULL);
		}
	}
}