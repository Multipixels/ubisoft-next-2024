//---------------------------------------------------------------------------------
// SceneManager.h
//---------------------------------------------------------------------------------
#pragma once

#include <map>
#include <memory>

#include "Scene/AbstractScene.h"

#define MAX_SCENES 10

namespace MultipixelEngine
{
	namespace Scene
	{
		class SceneManager
		{
			int currentSceneIndex = -1;
			int numOfScenes = 0;
			std::map<int, std::shared_ptr<Scene::AbstractScene>> sceneMap;

			SceneManager();

			size_t getNextSceneId();
		public:
			static SceneManager& Instance()
			{
				static SceneManager sceneManager;
				return sceneManager;
			}

			void addScene(std::shared_ptr<Scene::AbstractScene> sceneToAdd);
			std::shared_ptr<Scene::AbstractScene> getCurrentScene();
			int getCurrentSceneIndex();
			void changeScene(int sceneID);
		};
	}
}