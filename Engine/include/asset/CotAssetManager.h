#pragma once

#include "base/CotRule.h"
#include "CotAsset.h"
#include <unordered_map>

namespace Cot
{
	class COT_API AssetManager final
	{
		COT_SINGLETON_H(AssetManager);
	private:
		std::unordered_map<string, Asset*> _assets;

		Asset* GetAsset(const string& key);

	public:
		void Add(const string& key, Asset* asset);
		void Remove(const string& key);

		template <typename T>
		T Get(const string& key)
		{
			return static_cast<T>(GetAsset(key));
		}

		bool IsHave(const string& key);

		void DestroyAllAssets();

	};
}