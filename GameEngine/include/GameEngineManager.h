//---------------------------------------------------------------------------------
// GameEngine.h
//---------------------------------------------------------------------------------
#pragma once

// Actions Libraries
#include "Actions/Action.h"

// App Libraries
#include "App/app.h"

// Assert Library
#include "Assert/assert.h"

// Core Libraries
#include "Core/Vector2.h"

// Scene Libraries
#include "Scene/AbstractScene.h"
#include "Scene/Components.h"
#include "Scene/Entity.h"
#include "Scene/EntityManager.h"
#include "Scene/EntityMemoryPool.h"
#include "Scene/ErrorScene.h"

namespace GameEngine 
{
	class GameEngineManager
	{
		GameEngineManager();

		std::map<int, std::shared_ptr<Scene::AbstractScene>> sceneMap;
		std::map<int, Actions::ActionType> previousKeyStates;
		int currentSceneIndex = -1;

		bool crashed = false;
		std::string crashMessage = "";
		std::shared_ptr<ErrorScene> crashScene;
		;
	public:
		static GameEngineManager& Instance()
		{
			static GameEngineManager gameEngine;
			return gameEngine;
		}

		void init();
		void update(float deltaTime);
		void render();

		void crash(std::string message);
		void crash();

		void addScene(std::shared_ptr<Scene::AbstractScene> sceneToAdd);
		std::shared_ptr<Scene::AbstractScene> getCurrentScene();
		void changeScene(int sceneID);
		void registerAction(int actionKey);
	};

	//void Init() { GameEngineManager::Instance().init(); };
}

void Init();
void Update(float deltaTime);
void Render();
void Shutdown();