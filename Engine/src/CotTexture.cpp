#include "asset/CotTexture.h"
#include "asset/CotAssetManager.h"
#include "render/CotDx9Device.h"

namespace Cot
{
	Texture::Texture()
		: _filename("")
		, _texture(nullptr)
	{	}

	Texture::~Texture()
	{
		SafeRelease(_texture);
	}

	Texture* Texture::Load(const string& filename)
	{
		if (AssetManager::GetInstance().IsHave(filename))
		{
			return AssetManager::GetInstance().Get<Texture*>(filename);
		}

		Texture* result = new (std::nothrow) Texture();
		if (result != nullptr && result->Init(filename))
		{
			AssetManager::GetInstance().Add(filename, result);
			return result;
		}
		return nullptr;
	}

	bool Texture::Init(const string& filename)
	{
		_key = filename;
		_wkey = ToWString(filename);
		D3DXGetImageInfoFromFile(_wkey.c_str(), &_info);
		D3DXCreateTextureFromFileEx(Dx9Device::GetDevice(), _wkey.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2, 0, 1,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT, D3DX_DEFAULT,
			NULL, NULL, NULL, &_texture);

		return true;
	}
}