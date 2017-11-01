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
			result->Retain();
			return result;
		}
		return nullptr;
	}

	bool Texture::Init(const string& filename)
	{
		_filePath = filename;
		static uint ID_COUNT = 0;

		_id = ++ID_COUNT;

		string::size_type pos = string::npos;
		if ((pos = filename.find_last_of('/')) != string::npos)
		{
			_filename = filename.substr(pos + 1);
		}
		else if ((pos = filename.find_last_of('\\')) != string::npos)
		{
			_filename = filename.substr(pos + 1);
		}
		else
		{
			_filename = filename;
		}

		_key = filename;
		wstring wFilename = ToWString(filename);
		D3DXGetImageInfoFromFile(wFilename.c_str(), &_info);
		HRESULT result = D3DXCreateTextureFromFileEx(Dx9Device::GetDevice(), wFilename.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2, 0, 1,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT, D3DX_DEFAULT,
			NULL, NULL, NULL, &_texture);

		if (FAILED(result))
		{
			return false;
		}

		return true;
	}

	void Texture::Reload()
	{
		wstring wFilename = ToWString(_filePath);
		D3DXGetImageInfoFromFile(wFilename.c_str(), &_info);
		D3DXCreateTextureFromFileEx(Dx9Device::GetDevice(), wFilename.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2, 0, 1,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT, D3DX_DEFAULT,
			NULL, NULL, NULL, &_texture);
	}
}