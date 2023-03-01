#pragma once
#include <string>
#include "Transform.h"
#include "Component.h"

namespace gentgine
{
	class Font;
	class Texture2D;
	class Transform;
	class TextObject final : public Component
	{
	public:
		virtual void Update() override;
		virtual void Render() const override;
		virtual void SetOwner(std::shared_ptr<GameObject> owner);

		void SetText(const std::string& text);
		void SetFont(std::shared_ptr<Font> font);
		void SetPosition(float x, float y);

		TextObject(const std::string& text, std::shared_ptr<Font> font);
		TextObject();
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_needsUpdate{true};
		std::string m_text;
		Transform m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
