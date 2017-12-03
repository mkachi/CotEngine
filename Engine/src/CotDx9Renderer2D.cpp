#include "render/CotDx9Renderer2D.h"
#include "render/CotRenderManager.h"
#include "render/CotDx9Device.h"
#include "physics/CotPhysics.h"
#include "component/CotSpriteRenderer.h"
#include "component/CotFontRenderer.h"

namespace Cot
{
	Dx9Renderer2D::Dx9Renderer2D(int width, int height)
		: _mask(false)
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
		std::vector<IRenderComponent*> renderQ = RenderManager::GetInstance().GetRenderQ();

		if (renderQ.size() > 1)
		{
			std::sort(renderQ.begin(), renderQ.end(), [](IRenderComponent* a, IRenderComponent* b)->bool
			{
				return a->GetDepth() < b->GetDepth();
			});
		}

		_sprite->Begin(D3DXSPRITE_ALPHABLEND);

		for (uint i = 0; i < renderQ.size(); ++i)
		{
			if (renderQ[i]->IsUseMask())
			{
				_mask = true;
				Dx9Device::GetDevice()->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);

				Rect rect = renderQ[i]->GetMaskData()->GetRect();
				RECT dxMaskRect = ToDxMath(rect);
				SetRect(&dxMaskRect, 640, 360, 665, 909);
			//	dxMaskRect.top = renderQ[i]->GetMaskData()->GetRect().origin.y;
				Dx9Device::GetDevice()->SetScissorRect(&dxMaskRect);
			}

			if (renderQ[i]->GetRenderType() == IRenderComponent::Type::Font)
			{
				FontRenderer* fontRenderer = static_cast<FontRenderer*>(renderQ[i]);

				wstring text = ToWString(fontRenderer->GetText());
				_sprite->SetTransform(&ToDxMath(fontRenderer->GetOwner()->GetWorldMatrix()));

				fontRenderer->GetFont()->
					GetData()->DrawTextW(_sprite,
						text.c_str(), -1, 
						&ToDxMath(Rect(
							fontRenderer->GetOwner()->GetPosition().x, 
							fontRenderer->GetOwner()->GetPosition().y, 0.0f, 0.0f)), DT_NOCLIP,
						ToDxMath(fontRenderer->GetColor()));
			}
			else if (renderQ[i]->GetRenderType() == IRenderComponent::Type::Sprite)
			{
				SpriteRenderer* spriteRenderer = static_cast<SpriteRenderer*>(renderQ[i]);
				if (!Cot::IntersectRect(_screen, spriteRenderer->GetRect()))
				{
					continue;
				}

				Vec3 center = Vec3(
					spriteRenderer->GetRect().size.width * spriteRenderer->GetAnchor().x,
					spriteRenderer->GetRect().size.height * spriteRenderer->GetAnchor().y,
					0.0f);

				_sprite->SetTransform(&ToDxMath(spriteRenderer->GetOwner()->GetWorldMatrix()));
				_sprite->Draw(
					spriteRenderer->GetTexture()->GetTexture(),
					&ToDxMath(spriteRenderer->GetRect()),
					&ToDxMath(center),
					nullptr,
					ToDxMath(spriteRenderer->GetColor()));
			}

			if (_mask)
			{
				Dx9Device::GetDevice()->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
			}
		}
		_sprite->End();
		RenderManager::GetInstance().Clear();
	}

	void Dx9Renderer2D::Reset()
	{
		_sprite->OnResetDevice();
	}

	void Dx9Renderer2D::Lost()
	{
		_sprite->OnLostDevice();
	}
}