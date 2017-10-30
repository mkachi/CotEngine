#pragma once

#include "base/tinyxml2.h"
#include "base/CotApplication.h"
#include "base/CotEntity.h"

#include "component/CotSpriteRenderer.h"
#include "component/CotAnimation.h"
#include "component/CotAudioListener.h"
#include "component/CotAudioSource.h"
#include "component/CotBoxCollider.h"
#include "component/CotCircleCollider.h"

#include "math/CotMath.h"
#include "input/CotInput.h"

#include "container/CotVectorMap.hpp"
#include "container/CotQueue.hpp"

namespace Cot
{
	inline const char* GetVersion()
	{
		return "CotEngine v1.3";
	}
}