#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"
#include "Minigin.h"

namespace gentgine
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Awake();
		void Update();
		void FixedUpdate();
		void LateUpdate();
		void Render();
	private:
		friend class Singleton<SceneManager>;
		

		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_scenes;

	
	};
}
