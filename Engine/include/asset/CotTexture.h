#pragma once

#include "CotAsset.h"
#include "math/CotMath.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Texture
		: public Asset
	{
	private:
		uint				_id;
		std::string			_filename;
		D3DXIMAGE_INFO		_info;
		IDirect3DTexture9*	_texture;

		bool Init(const string& filename);

	protected:
		Texture();

	public:
		virtual ~Texture();

		static Texture* Load(const string& filename);
		IDirect3DTexture9* GetTexture() { return _texture; }

		string GetFilename() { return _filename; }

		uint GetId() { return _id; }

		uint GetWidth() { return _info.Width; }
		uint GetHeight() { return _info.Height; }

	};
}