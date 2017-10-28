#include "render/CotDx9Renderer2D.h"
#include "render/CotRenderManager.h"
#include "render/CotDx9Device.h"
#include "physics/CotPhysics.h"
#include <algorithm>

namespace Cot
{
	Dx9Renderer2D::Dx9Renderer2D(int width, int height)
	{
		_screen.SetRect(0.0f, 0.0f, width, height);
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
			if (!Cot::IntersectRect(_screen, renderQ[i]->GetRect()))
			{
				continue;
			}

			Vec3 center = Vec3(
				renderQ[i]->GetRect().size.width * renderQ[i]->GetAnchor().x,
				renderQ[i]->GetRect().size.height * renderQ[i]->GetAnchor().y,
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