//---------------------------------------------------------------------------------
// GameEngine.h
//---------------------------------------------------------------------------------
#pragma once

#include <memory>

// App Library
#include "App/app.h"

// Assert Library
#include "Assert/assert.h"

// Core Library
#include "Core/Components.h"
#include "Core/GameObject.h"
#include "Core/GameObjectManager.h"
#include "Core/GameObjectMemoryPool.h"
#include "Core/Vector2.h"

// Events Library
#include "Events/Action.h"

// Scene Library
#include "Scene/AbstractScene.h"
#include "Scene/ErrorScene.h"
#include "Scene/SceneManager.h"

namespace MultipixelEngine 
{
	class GameEngine
	{
		GameEngine();

		std::map<int, Events::ActionType> previousKeyStates;
		SceneManager& sceneManager;

		bool crashed = false;
		std::string crashMessage = "";
		std::shared_ptr<ErrorScene> crashScene;
	public:
		static GameEngine& Instance()
		{
			static GameEngine gameEngine;
			return gameEngine;
		}

		void init();
		void update(float deltaTime);
		void render();

		void crash(std::string message);
		void crash();

		void registerAction(int actionKey);
	};
}



// Defined in the global namespace to then redirect to GameEngine namespace.

void Init();
void Update(float deltaTime);
void Render();
void Shutdown();