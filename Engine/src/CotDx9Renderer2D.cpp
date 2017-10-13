#include "render/CotDx9Renderer2D.h"
#include "render/CotRenderManager.h"
#include "render/CotDx9Device.h"
#include <algorithm>

namespace Cot
{
	Dx9Renderer2D::Dx9Renderer2D()
		: _sprite(nullptr)
	{
		D3DXCreateSprite(Dx9Device::GetDevice(), &_sprite);
	}

	Dx9Renderer2D::~Dx9Renderer2D()
	{
		SafeRelease(_sprite);
	}

	void Dx9Renderer2D::Draw()
	{
		std::vector<SpriteRenderer*> renderQ = RenderManager::GetInstance().GetRenderQ();

		if (renderQ.size() > 1)
		{
			std::sort(renderQ.begin(), renderQ.end(), [](SpriteRenderer* a, SpriteRenderer* b)->bool
			{
				return a->GetDepth() < b->GetDepth();
			});
		}

		_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		for (auto& renderer : renderQ)
		{
			Vec3 center = Vec3(
				renderer->GetTexture()->GetWidth() * renderer->GetAnchor().x,
				renderer->GetTexture()->GetHeight() * renderer->GetAnchor().y,
				0.0f);

			_sprite->SetTransform(&ToDxMath(renderer->GetOwner()->GetWorldMatrix()));
			if (renderer->IsAtlasSprite())
			{
				_sprite->Draw(
					renderer->GetTexture()->GetTexture(),
					&ToDxMath(renderer->GetAtlasRect()),
					&ToDxMath(center),
					nullptr,
					ToDxMath(renderer->GetColor()));
			}
			else
			{
				_sprite->Draw(
					renderer->GetTexture()->GetTexture(),
					NULL,
					&ToDxMath(center),
					nullptr,
					ToDxMath(renderer->GetColor()));
			}
		}
		_sprite->End();
		RenderManager::GetInstance().Clear();
	}
}