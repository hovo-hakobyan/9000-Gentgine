#pragma once
#include <memory>


namespace gentgine
{
	class GameObject;
	class Component 
	{
	public:

		Component() = default;
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;


		virtual void Awake() {}
		virtual void Update(){}
		virtual void LateUpdate(){}
		virtual void FixedUpdate(){}
		virtual void Render() const {}

		virtual void SetOwner(std::shared_ptr<GameObject> owner) = 0;

	protected:
		std::weak_ptr<GameObject> m_GameObject;


	private:
	};

}
