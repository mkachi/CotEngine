#pragma once

#include "base/CotNode.h"
#include <d3dx9.h>

namespace Cot
{
	class COT_API Object
		: public Node
	{
	protected:
		bool _active;
		D3DXVECTOR3		_position;
		D3DXVECTOR3		_rotate;
		D3DXVECTOR3		_scale;

	public:
		Object();
		virtual ~Object();

		void SetPosition(D3DXVECTOR3 position);
		void SetPositionX(float x);
		void SetPositionY(float y);
		void SetPositionZ(float z);
		D3DXVECTOR3 GetPosition() { return _position; }

		void SetActive(bool active);
		bool IsActive() { return _active; }

		virtual void Update();

	};
}