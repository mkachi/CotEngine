#include "component/CotMask.h"
#include "component/CotSpriteRenderer.h"
#include "component/CotFontRenderer.h"

namespace Cot
{
	Mask* Mask::Init(SpriteRenderer* renderer)
	{
		_renderer = renderer;

		return this;
	}

	void Mask::Start()
	{
		_renderer->SetMask(this, true);
		_maskRect = _renderer->GetRect();

		_maskRect = _renderer->GetRect();
		Vec3 position = _renderer->GetOwner()->GetPosition();
		_maskRect.SetRect(position.x, position.y, _maskRect.size.width, _maskRect.size.height);

		Entity* entity = _renderer->GetOwner();
		std::vector<Entity*> children = entity->GetChildren();
		for (auto& child : children)
		{
			SpriteRenderer* spriteRenderer = child->GetComponent<SpriteRenderer>();
			if (spriteRenderer != nullptr)
			{
				spriteRenderer->SetMask(this, true);
			}

			FontRenderer* fontRenderer = child->GetComponent<FontRenderer>();
			if (fontRenderer != nullptr)
			{
				fontRenderer->SetMask(this, true);
			}
		}
	}
}