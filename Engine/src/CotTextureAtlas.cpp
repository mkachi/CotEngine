#include "asset/CotTextureAtlas.h"
#include "asset/CotAssetManager.h"

namespace Cot
{
	TextureAtlas::TextureAtlas()
	{	}
	
	TextureAtlas::~TextureAtlas()
	{
		if (_texture != nullptr)
		{
			_texture->Release();
		}
	}
	
	bool TextureAtlas::Init(const string& key, Texture* texture, const Rect& rect)
	{
		_key = key;
		_texture = texture;
		_texture->Retain();
		_rect = rect;

		return true;
	}

	TextureAtlas* TextureAtlas::Load(const string& key, Texture* texture, const Rect& rect)
	{
		if (AssetManager::GetInstance().IsHave(key))
		{
			return AssetManager::GetInstance().Get<TextureAtlas*>(key);
		}

		TextureAtlas* result = new (std::nothrow) TextureAtlas();
		if (result != nullptr && result->Init(key, texture, rect))
		{
			AssetManager::GetInstance().Add(key, result);
			result->Retain();
			return result;
		}
		return nullptr;
	}
}