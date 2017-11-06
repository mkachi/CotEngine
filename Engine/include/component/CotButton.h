#pragma once

#include "CotSpriteRenderer.h"
#include "physics/CotPhysics.h"
#include "base/CotCallBack.hpp"

namespace Cot
{
	Component(Button, COT_API)
	{
		COT_COMPONENT(Button);
	private:
		enum class Type { Color, Image, };
		Type				_buttonType;
		SpriteRenderer*		_spriteRenderer;
		Texture*			_originImage;
		Texture*			_clickImage;
		Color				_originColor;
		Color				_clickColor;
		bool				_down;

		CallBack<void()>	_buttonDown;
		CallBack<void()>	_buttonUp;
		CallBack<void()>	_buttonClick;

	public:
		// Image
		Button* Init(const string& clickImage);
		Button* Init(const Color& clickColor);

		void Reset() override;
		void Awake() override;
		void Update(Time& time) override;

		void AddButtonDown(const Function<void()>& function);
		void AddButtonUp(const Function<void()>& function);
		void AddButtonClick(const Function<void()>& function);

	};
}