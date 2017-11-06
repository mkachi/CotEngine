#include "component/CotButton.h"
#include "input/CotInput.h"

namespace Cot
{
	Button* Button::Init(const string& clickImage)
	{
		Reset();
		_buttonType = Type::Image;
		_clickImage = Texture::Load(clickImage);
		return this;
	}

	Button* Button::Init(const Color& clickColor)
	{
		Reset();
		_buttonType = Type::Color;
		_clickColor = clickColor;
		return this;
	}

	void Button::Reset()
	{
		_buttonType = Type::Color;
		_down = false;
		_originColor = Color::White;
		_clickColor = Color::White;
	}

	void Button::Awake()
	{
		_spriteRenderer = GetOwner()->GetComponent<SpriteRenderer>();
		_originImage = _spriteRenderer->GetTexture();
		_originColor = _spriteRenderer->GetColor();

		if (_buttonType == Type::Color)
		{
			_spriteRenderer->SetColor(_originColor);
		}
		else
		{
			_spriteRenderer->SetTexture(_originImage);
		}
	}

	void Button::Update(Time& time)
	{
		if (IsMouseDown(MouseButton::LButton))
		{
			Rect rect;
			rect.SetRect(
				GetOwner()->GetPosition().x,
				GetOwner()->GetPosition().y,
				_spriteRenderer->GetRect().size.width,
				_spriteRenderer->GetRect().size.height);
			if (PointInRect(rect, GetMousePosition()))
			{
				_down = true;
				_buttonDown.Invoke();

				if (_buttonType == Type::Color)
				{
					_spriteRenderer->SetColor(_clickColor);
				}
				else
				{
					_spriteRenderer->SetTexture(_clickImage);
				}
			}
		}

		if (_down)
		{
			if (IsMouseUp(MouseButton::LButton))
			{
				Rect rect;
				rect.SetRect(
					GetOwner()->GetPosition().x,
					GetOwner()->GetPosition().y,
					_spriteRenderer->GetRect().size.width,
					_spriteRenderer->GetRect().size.height);
				if (PointInRect(rect, GetMousePosition()))
				{
					_buttonClick.Invoke();
				}

				_down = false;
				_buttonUp.Invoke();
				
				if (_buttonType == Type::Color)
				{
					_spriteRenderer->SetColor(_originColor);
				}
				else
				{
					_spriteRenderer->SetTexture(_originImage);
				}
			}
		}
	}

	void Button::AddButtonDown(const Function<void()>& function)
	{
		_buttonDown.Add(function);
	}

	void Button::AddButtonUp(const Function<void()>& function)
	{
		_buttonUp.Add(function);
	}

	void Button::AddButtonClick(const Function<void()>& function)
	{
		_buttonClick.Add(function);
	}
}