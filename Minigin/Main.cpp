#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "Includes.h"
#include "GameObject.h"

void load()
{
	
	auto& scene = gentgine::SceneManager::GetInstance().CreateScene("Week1");
	auto font = gentgine::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	//Background
	auto gameObj = std::make_shared<gentgine::GameObject>();
	gameObj->AddComponent<gentgine::RenderComponent>("background.tga");

	scene.Add(gameObj);

	//Foreground Title
	gameObj = std::make_shared<gentgine::GameObject>();
	auto textComponent = gameObj->AddComponent<gentgine::TextObject>("Programming 4 Assignment", font);
	textComponent->SetPosition(100, 180);

	scene.Add(gameObj);

	//Logo
	gameObj = std::make_shared<gentgine::GameObject>();
	gameObj->SetPosition(216, 350);
	auto logoRenderComp = gameObj->AddComponent<gentgine::RenderComponent>("logo.tga");

	scene.Add(gameObj);
	

	//FPS, To be implemented
	

}

int main(int, char*[]) {
	gentgine::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}