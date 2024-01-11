//---------------------------------------------------------------------------------
// SceneManager.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/SceneManager.h"
//#include "Assert/assert.h"

namespace MultipixelEngine
{
	namespace Scene
	{
		SceneManager::SceneManager()
		{

		}

		void SceneManager::addScene(std::shared_ptr<Scene::AbstractScene> sceneToAdd)
		{
			// TODO: GET NEW KEY
			sceneMap[0] = (sceneToAdd);
		}

		std::shared_ptr<Scene::AbstractScene> SceneManager::getCurrentScene()
		{
			//ASSERT(sceneMap.count(currentSceneIndex), "Could not get current scene");
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