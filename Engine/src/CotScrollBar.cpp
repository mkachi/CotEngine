#include "component/CotScrollBar.h"
#include "render/CotRenderManager.h"
#include "asset/CotTextureAtlas.h"
#include "asset/CotAssetManager.h"
#include "component/CotButton.h"
#include "input/CotInput.h"

namespace Cot
{
	ScrollBar* ScrollBar::Init(const string& background, Entity* button)
	{
		Reset();
		SpriteRenderer::Init(background);

		_button = button;
		_button->SetParent(this->GetOwner());
		_button->SetPosition(Vec2(0.0f, 0.0f));
		_button->GetComponent<SpriteRenderer>()->SetDepth(_depth + 1);
		Button* buttonCom = _button->GetComponent<Button>();

		float buttonHeight = _button->GetComponent<SpriteRenderer>()->GetSize().height;
		_maxValue = (_size.height / 2) - (buttonHeight / 2);
		_minValue = -_maxValue;
		_button->SetPositionY(_minValue);

		buttonCom->AddButtonDown([=]() 
		{
			_buttonDown = true;
			_beginY = GetMousePosition().y;
			_endY = GetMousePosition().y;
		});

		buttonCom->AddButtonUp([=]() 
		{
			_buttonDown = false;
		});

		return this;
	}

	void ScrollBar::Reset()
	{
		_renderType = IRenderComponent::Type::Sprite;
		SafeRelease(_texture);
		_buttonDown = false;
		_texture = nullptr;
		_button = nullptr;
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		_depth = 0;
	}

	void ScrollBar::Update(Time& time)
	{
		if (_texture == nullptr)
		{
			return;
		}
		RenderManager::GetInstance().Add(this);

		if (_buttonDown && IsMouseStay(MouseButton::LButton))
		{
			_beginY = GetMousePosition().y;
			float buttonY = _button->GetLocalPosition().y - (_endY - _beginY);
			float y = Clamp(buttonY, _minValue, _maxValue);
			_button->SetLocalPositionY(y);
			_endY = GetMousePosition().y;
			_value = (y - _minValue) / (_maxValue * 2);
		}
	}

	void ScrollBar::OnDestroy()
	{
		SafeRelease(_texture);
	}

	void ScrollBar::SetValue(float value)
	{
		_value = value;
		float y = _maxValue * value;
		_button->SetLocalPositionY(y);
	}
}