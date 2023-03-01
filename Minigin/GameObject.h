#pragma once
#include <vector>
#include "Transform.h"
#include "Component.h"
#include "TextObject.h"

namespace gentgine
{
	class Texture2D;
	

	class GameObject final: public std::enable_shared_from_this<GameObject>
	{
	public:
		void Awake();
		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render() const;

		void SetPosition(float x, float y);
		glm::vec3 GetPosition() const;

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template<typename CompType,typename... Args>
		std::shared_ptr<CompType> AddComponent(Args&&... args)
		{
			if (!std::is_base_of<Component, CompType>::value)
			{
				return nullptr;
			}

			std::shared_ptr<CompType> newComp;

			//Does the component have a constructor that takes the given arguments?
			if constexpr (std::is_constructible_v<CompType, Args...>)
			{
				newComp = std::make_shared<CompType>(std::forward<Args>(args)...);
				newComp->SetOwner(shared_from_this());

				m_Components.push_back(newComp);
			}
			
			return newComp;
				
		}

		
		bool RemoveComponent(std::shared_ptr<Component> component) 		
		{
			auto it = std::find(m_Components.begin(), m_Components.end(), component);
			if (it != m_Components.end())
			{
				m_Components.erase(it);
				return true;
			}
			return false;
				
		}

		//Heavy operation try to avoid during updates
		//Cache the component if you are going to use it
		template<typename CompType>
		std::weak_ptr<CompType> GetComponent()
		{
			for (const auto& comp : m_Components)
			{
				if (std::weak_ptr<CompType> ptr = std::dynamic_pointer_cast<CompType>(comp))
				{
					return ptr;
				}
			}

			return {};
		}

		template<typename CompType>
		bool HasComponent()
		{
			for (const auto& comp : m_Components)
			{
				if (auto ptr = std::dynamic_pointer_cast<CompType>(comp))
				{
					return true;
				}
			}

			return false;
		}

	protected:
		Transform m_transform{};
	private:
		std::vector<std::shared_ptr<Component>> m_Components;
	};
}
