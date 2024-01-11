//---------------------------------------------------------------------------------
// SceneManager.h
//---------------------------------------------------------------------------------
#pragma once

#include <map>
#include <memory>

#include "Scene/AbstractScene.h"

namespace MultipixelEngine
{
	namespace Scene
	{
		class SceneManager
		{
			SceneManager();

			std::map<int, std::shared_ptr<Scene::AbstractScene>> sceneMap;

			int currentSceneIndex = -1;
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