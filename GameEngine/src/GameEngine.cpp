//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngine.h"
#include "App/app.h"

namespace MultipixelEngine 
{
	GameEngine::GameEngine() 
		: sceneManager(SceneManager::Instance()),
		  eventManager(EventManager::Instance()),
		  renderSystem(RenderSystem::Instance())
	{
		init();
	}

	void GameEngine::init()
	{
		// TODO: Load assets

		// Reverts option set in main.cpp,
		// Fixes a bug with the assert macro in which it will return to the code that would have caused an exception.
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_EXIT);
	}
	
	void GameEngine::update(float deltaTime)
	{
		if (crashed)
		{
			crashScene->update();
			return;
		}

		EventManager::Instance().detectEvent();
		sceneManager.getCurrentScene()->update();
	}

	void GameEngine::render()
	{
		if (crashed)
		{
			renderSystem.render(crashScene);
			return;
		}

		renderSystem.render(sceneManager.getCurrentScene());
	}

	void GameEngine::crash(std::string message)
	{
		if (crashed) return;
		render();
		crashed = true;
		crashScene = std::make_shared<ErrorScene>(message);
		glutMainLoop();
	}

	void GameEngine::crash()
	{
		crashed = true;
		crashScene = std::make_shared<ErrorScene>("");
	}
}

void Update(float deltaTime) 
{ 
	MultipixelEngine::GameEngine::Instance().update(deltaTime);
}

void Render() 
{ 
	MultipixelEngine::GameEngine::Instance().render();
}

void Shutdown()
{

}