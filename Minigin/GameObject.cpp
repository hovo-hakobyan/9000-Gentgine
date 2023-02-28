#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

gentgine::GameObject::~GameObject() = default;

void gentgine::GameObject::Update(){}

void gentgine::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void gentgine::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void gentgine::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
