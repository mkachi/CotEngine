#include "render/CotDx9Renderer2D.h"

namespace Cot
{
	Dx9Renderer2D::Dx9Renderer2D(IDirect3DDevice9* device)
		: _sprite(nullptr)
		, _device(device)
	{
		D3DXCreateSprite(device, &_sprite);
	}

	Dx9Renderer2D::~Dx9Renderer2D()
	{
		SafeRelease(_sprite);
	}

	void Dx9Renderer2D::Draw()
	{
		_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	//	_sprite->Draw(_texture, nullptr, nullptr, &D3DXVECTOR3(_transform->GetPosition().x, _transform->GetPosition().y, 0), 0xffffffff);
		_sprite->End();
	}
}