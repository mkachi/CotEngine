#include "render/CotDx9Renderer2D.h"
#include "render/CotRenderManager.h"
#include "render/CotDx9Device.h"
#include <algorithm>

namespace Cot
{
	Dx9Renderer2D::Dx9Renderer2D()
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

		_sprite->Begin(D3DXSPRITE_ALPHABLEND);
		for (uint i = 0; i < renderQ.size(); ++i)
		{
			Vec3 center = Vec3(
				renderQ[i]->GetTexture()->GetWidth() * renderQ[i]->GetAnchor().x,
				renderQ[i]->GetTexture()->GetHeight() * renderQ[i]->GetAnchor().y,
				0.0f);

			_sprite->SetTransform(&ToDxMath(renderQ[i]->GetOwner()->GetWorldMatrix()));
			_sprite->Draw(
				renderQ[i]->GetTexture()->GetTexture(),
				&ToDxMath(renderQ[i]->GetRect()),
				&ToDxMath(center),
				nullptr,
				ToDxMath(renderQ[i]->GetColor()));
		}
		_sprite->End();
		RenderManager::GetInstance().Clear();
	}
}