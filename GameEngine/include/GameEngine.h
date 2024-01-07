#pragma once

#include "App/app.h"

// Actions Libraries
#include "Actions/Action.h"

// Core Libraries
#include "Core/Vector2.h"

// Scene Libraries
#include "Scene/Components.h"
#include "Scene/Entity.h"
#include "Scene/EntityManager.h"
#include "Scene/EntityMemoryPool.h"
#include "Scene/Scene.h"

namespace GameEngine 
{
	class GameEngine
	{
		GameEngine();

		std::vector<std::shared_ptr<Scene::Scene>> sceneMap;
		int currentScene = -1;
	public:
		static GameEngine& Instance()
		{
			static GameEngine gameEngine;
			return gameEngine;
		}

		void init();
		void update(float deltaTime);
		void render();

		void addScene(std::shared_ptr<Scene::Scene> sceneToAdd);
		std::shared_ptr<Scene::Scene> getCurrentScene();
		void changeScene(int sceneID);
	};

	void Init() { GameEngine::Instance().init(); };
	void Update(float deltaTime) { GameEngine::Instance().update(deltaTime); };
	void Render() { GameEngine::Instance().render(); };
	void Shutdown();
}