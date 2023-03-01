#include "RenderComponent.h"
#include "Font.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Renderer.h"

gentgine::RenderComponent::RenderComponent(const std::string& path)
	: Component()
{
	SetTexture(path);
}


void gentgine::RenderComponent::SetOwner(std::shared_ptr<GameObject> owner)
{
	m_GameObject = owner;
}

void gentgine::RenderComponent::Render() const
{


	if (m_pTexture)
	{
		const auto& pos = m_GameObject.lock()->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void gentgine::RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture= ResourceManager::GetInstance().LoadTexture(filename);
}

