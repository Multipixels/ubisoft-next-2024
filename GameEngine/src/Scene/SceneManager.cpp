//---------------------------------------------------------------------------------
// SceneManager.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/SceneManager.h"
#include "Assert/assert.h"

namespace MultipixelEngine
{
	namespace Scene
	{
		SceneManager::SceneManager()
		{

		}

		size_t SceneManager::getNextSceneId()
		{
			numOfScenes++;
			return numOfScenes - 1;
		};

		void SceneManager::addScene(std::shared_ptr<Scene::AbstractScene> sceneToAdd)
		{
			int sceneId = getNextSceneId();
			ASSERT(sceneId >= MAX_SCENES, "Too many scenes! You can only have a maximum of 10 scenes.");

			sceneMap[sceneId] = (sceneToAdd);
		}

		std::shared_ptr<Scene::AbstractScene> SceneManager::getCurrentScene()
		{
			ASSERT(sceneMap.count(currentSceneIndex), "Could not get current scene");
			return sceneMap[currentSceneIndex];
		}

		int SceneManager::getCurrentSceneIndex()
		{
			return currentSceneIndex;
		}

		void SceneManager::changeScene(int sceneID)
		{
			currentSceneIndex = sceneID;
			getCurrentScene()->init();
		}
	}
}