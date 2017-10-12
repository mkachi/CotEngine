#pragma once

#include "base/CotNode.h"
#include "math/CotMath.h"

namespace Cot
{
	class COT_API Entity
		: public Node
	{
	protected:
		bool	_active;
		Vec3	_position;
		Vec3	_rotate;
		Vec3	_scale;

	public:
		Entity();
		virtual ~Entity();

		void SetPosition(const Vec3& position);
		void SetPositionX(float x);
		void SetPositionY(float y);
		void SetPositionZ(float z);
		Vec3 GetPosition() { return _position; }

		void SetRotate(const Vec3& rotate);
		void SetRotateX(float x);
		void SetRotateY(float y);
		void SetRotateZ(float z);
		Vec3 GetRotate() { return _rotate; }

		void SetScale(const Vec3& scale);
		void SetScaleX(float x);
		void SetScaleY(float y);
		void SetScaleZ(float z);
		Vec3 GetScale() { return _scale; }

		void SetActive(bool active);
		bool IsActive() { return _active; }

		virtual Entity* GetParent() { return static_cast<Entity*>(_parent); }

		virtual void Update();

	};
}