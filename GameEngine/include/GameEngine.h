//---------------------------------------------------------------------------------
// GameEngine.h
//---------------------------------------------------------------------------------
#pragma once

#include <memory>

// Assert Library
#include "Assert/assert.h"

// Core Library
#include "Core/Components.h"
#include "Core/GameObject.h"
#include "Core/GameObjectManager.h"
#include "Core/GameObjectMemoryPool.h"
#include "Core/RenderSystem.h"
#include "Core/Vector2.h"

// Events Library
#include "Events/Action.h"
#include "Events/EventManager.h"

// Scene Library
#include "Scene/AbstractScene.h"
#include "Scene/ErrorScene.h"
#include "Scene/SceneManager.h"

namespace MultipixelEngine 
{
	class GameEngine
	{
		GameEngine();

		EventManager& eventManager;
		SceneManager& sceneManager;
		RenderSystem& renderSystem;

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
	};
}



// Defined in the global namespace to then redirect to game engine's and game's namespace.

void Init();
void Update(float deltaTime);
void Render();
void Shutdown();