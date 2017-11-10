#include "component/CotPrograssBar.h"

namespace Cot
{
	void PrograssBar::Reset()
	{
		_value = 0.0f;
		_spriteRenderer = nullptr;
	}

	void PrograssBar::Awake()
	{
		Reset();
		_spriteRenderer = GetOwner()->GetComponent<SpriteRenderer>();
		_spriteRenderer->SetAnchor(Vec2(0.0f, 0.5f));
	}

	void PrograssBar::SetValue(float value)
	{
		if (_spriteRenderer == nullptr)
		{
			_spriteRenderer = GetOwner()->GetComponent<SpriteRenderer>();
		}
		GetOwner()->SetDirty(true);
		_value = Clamp(value, 0.0f, 1.0f);

		Rect rect = _spriteRenderer->GetRect();
		float delta = rect.size.width;
		float width = _spriteRenderer->GetSize().width * _value;
		delta -= width;
		delta /= 2.0f;

		rect.SetRect(
			rect.origin.x,
			rect.origin.y,
			width,
			rect.size.height
		);
		_spriteRenderer->SetRect(rect);
	}
}