#pragma once

#include "asset/CotAudioClip.h"
#include "asset/CotTexture.h"
#include "asset/CotFont.h"
#include "asset/CotTextureAtlas.h"
#include "asset/CotAssetManager.h"

#include "base/tinyxml2.h"
#include "base/CotApplication.h"
#include "base/CotEntity.h"
#include "base/CotSceneManager.h"

#include "component/CotAudioListener.h"
#include "component/CotAudioSource.h"

#include "component/CotFontRenderer.h"
#include "component/CotSpriteRenderer.h"
#include "component/CotAnimation.h"

#include "component/CotBoxCollider.h"
#include "component/CotCircleCollider.h"

#include "component/CotButton.h"
#include "component/CotPrograssBar.h"
#include "component/CotScrollBar.h"

#include "math/CotMath.h"
#include "input/CotInput.h"

#include "container/CotVectorMap.hpp"
#include "container/CotQueue.hpp"

namespace Cot
{
	COT_API inline const char* GetVersion()
	{
		return "CotEngine v1.4.7";
	}
}