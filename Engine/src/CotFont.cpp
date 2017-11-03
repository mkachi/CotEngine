#include "asset/CotFont.h"
#include "asset/CotAssetManager.h"
#include "render/CotDx9Device.h"

namespace Cot
{
	Font::Font()
		: _d3dFont(nullptr)
	{	}

	Font::~Font()
	{
		SafeRelease(_d3dFont);
	}

	Font* Font::Load(const string& filename, int fontSize)
	{
		string key = filename + "#" + ToString(fontSize);
		if (AssetManager::GetInstance().IsHave(key))
		{
			return AssetManager::GetInstance().Get<Font*>(key);
		}

		Font* result = new (std::nothrow) Font();
		if (result != nullptr && result->Init(filename, fontSize))
		{
			AssetManager::GetInstance().Add(key, result);
			result->Retain();
			return result;
		}
		return nullptr;
	}

	bool Font::Init(const string& filename, int fontSize)
	{
		_filePath = filename;

		string::size_type pos = string::npos;
		_fontPath = filename;
		if ((pos = filename.find_last_of('/')) != string::npos)
		{
			_fontName = filename.substr(pos + 1);
		}
		else if ((pos = filename.find_last_of('\\')) != string::npos)
		{
			_fontName = filename.substr(pos + 1);
		}
		else
		{
			_fontName = filename;
		}

		_key = filename + "#" + ToString(fontSize);
		_fontSize = fontSize;

		wstring wFilename = ToWString(filename);
		AssetManager::GetInstance().AddFontCache(filename);
		HRESULT result = D3DXCreateFont(Dx9Device::GetDevice(), _fontSize, 0, FW_NORMAL, 1, false, 
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, wFilename.c_str(), &_d3dFont);
		if (FAILED(result))
		{
			return false;
		}
		return true;
	}

	void Font::Reload()
	{
		SafeRelease(_d3dFont);
		wstring wFilename = ToWString(_filePath);
		D3DXCreateFont(Dx9Device::GetDevice(), _fontSize, 0, FW_NORMAL, 1, false,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, wFilename.c_str(), &_d3dFont);
	}
}