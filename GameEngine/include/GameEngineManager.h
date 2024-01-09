//---------------------------------------------------------------------------------
// GameEngine.h
//---------------------------------------------------------------------------------
#pragma once

// Actions Libraries
#include "Actions/Action.h"

// App Libraries
#include "App/app.h"

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
	class GameEngineManager
	{
		GameEngineManager();

		std::vector<std::shared_ptr<Scene::Scene>> sceneMap;
		std::map<int, Actions::ActionType> previousKeyStates;
		int currentSceneIndex = -1;
	public:
		static GameEngineManager& Instance()
		{
			static GameEngineManager gameEngine;
			return gameEngine;
		}

		void init();
		void update(float deltaTime);
		void render();

		void addScene(std::shared_ptr<Scene::Scene> sceneToAdd);
		std::shared_ptr<Scene::Scene> getCurrentScene();
		void changeScene(int sceneID);
		void registerAction(int actionKey);
	};

	//void Init() { GameEngineManager::Instance().init(); };
}

void Init();
void Update(float deltaTime);
void Render();
void Shutdown();