#include "component/CotSpriteRenderer.h"
#include "render/CotRenderManager.h"
#include "asset/CotTextureAtlas.h"
#include "asset/CotAssetManager.h"
#include "base/tinyxml2.h"

namespace Cot
{
	SpriteRenderer* SpriteRenderer::Init(const string& filename)
	{
		Reset();
		_texture = Texture::Load(filename);
		_texture->Retain();
		_rect = Rect(0, 0, _texture->GetWidth(), _texture->GetHeight());
		_size = Size(_texture->GetWidth(), _texture->GetHeight());
		return this;
	}

	SpriteRenderer* SpriteRenderer::Init(const string& caif, const string& key)
	{
		Reset();
		string atlasKey = (caif + "@" + key);
		if (AssetManager::GetInstance().IsHave(atlasKey))
		{
			TextureAtlas* atlas = AssetManager::GetInstance().Get<TextureAtlas*>(atlasKey);
			_texture = atlas->GetTexture();
			_texture->Retain();
			_rect = atlas->GetRect();
			_size = _rect.size;
			return this;
		}

		tinyxml2::XMLDocument document;
		document.LoadFile(caif.c_str());

		tinyxml2::XMLElement* imageElement = document.FirstChildElement();
		string image = imageElement->Attribute("image");

		string imagePath = image;
		string::size_type pos = caif.find_last_of("\\");
		if (pos != string::npos)
		{
			imagePath = caif.substr(0, caif.find_last_of("\\") + 1) + image;
		}

		tinyxml2::XMLElement* element = imageElement->FirstChildElement("count");
		uint imageCount = atoi(element->Attribute("value"));

		TextureAtlas* data = nullptr;
		element = element->NextSiblingElement();
		for (uint i = 0; i < imageCount; ++i)
		{
			string k = element->Attribute("k");
			uint x = element->IntAttribute("x");
			uint y = element->IntAttribute("y");
			uint w = element->IntAttribute("w");
			uint h = element->IntAttribute("h");
			element = element->NextSiblingElement();

			Rect rect;
			rect.SetRect(x, y, w, h);

			TextureAtlas* atlas = TextureAtlas::Load((caif + "@" + k), Texture::Load(imagePath), rect);
			if (k == key)
			{
				data = atlas;
			}
		}
		document.Clear();

		_texture = data->GetTexture();
		_texture->Retain();
		_rect = data->GetRect();

		return this;
	}

	void SpriteRenderer::Reset()
	{
		_renderType = IRenderComponent::Type::Sprite;
		SafeRelease(_texture);
		_texture = nullptr;
		_anchor = Vec2(0.5f, 0.5f);
		_color = Color::White;
		_depth = 0;
	}

	void SpriteRenderer::Update(Time& time)
	{
		if (_texture == nullptr)
		{
			return;
		}
		RenderManager::GetInstance().Add(this);
	}

	void SpriteRenderer::OnDestroy()
	{
		SafeRelease(_texture);
	}

	void SpriteRenderer::SetTexture(Texture* texture)
	{
		SafeRelease(_texture);
		_texture = texture;
		_texture->Retain();
		_rect = Rect(0, 0, _texture->GetWidth(), _texture->GetHeight());
	}

	void SpriteRenderer::SetTexture(const string& filename)
	{
		SafeRelease(_texture);
		Init(filename);
	}

	void SpriteRenderer::SetTexture(const string& caif, const string& key)
	{
		SafeRelease(_texture);
		Init(caif, key);
	}
}