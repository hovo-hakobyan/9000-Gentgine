#pragma once
#include "Component.h"
#include <string>

namespace gentgine 
{
	
	class Texture2D;
	class Font;
	class RenderComponent final: public Component
	{
	public:
		virtual void SetOwner(std::shared_ptr<GameObject> owner);
		virtual void Render() const override;

		void SetTexture(const std::string& filename);

		RenderComponent(const std::string& path);
		virtual ~RenderComponent() = default;
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

	private:
		std::shared_ptr<Texture2D> m_pTexture{};
	};
}



