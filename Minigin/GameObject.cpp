#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"

gentgine::GameObject::~GameObject() = default;

void gentgine::GameObject::Awake()
{
	for (auto& obj : m_Components)
	{
		obj->Awake();
	}
}

void gentgine::GameObject::Update()
{
	for (auto& obj : m_Components)
	{
		obj->Update();
	}
}

void gentgine::GameObject::LateUpdate()
{
	for (auto& obj : m_Components)
	{
		obj->LateUpdate();
	}
}

void gentgine::GameObject::FixedUpdate()
{
	for (auto& obj : m_Components)
	{
		obj->FixedUpdate();
	}
}

void gentgine::GameObject::Render() const
{
	for (auto& obj : m_Components)
	{
		obj->Render();
	}
}


void gentgine::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

glm::vec3 gentgine::GameObject::GetPosition() const
{
	return m_transform.GetPosition();
}
