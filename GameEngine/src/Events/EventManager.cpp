//---------------------------------------------------------------------------------
// EventManager.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Events/EventManager.h"
#include "App/app.h"
#include "Scene/SceneManager.h"

namespace MultipixelEngine
{
	namespace Events
	{
		EventManager::EventManager()
		{

		}

		void EventManager::registerAction(int actionKey)
		{
			previousKeyStates[actionKey] = Events::NONE;
		}

		void EventManager::detectEvent()
		{
			auto currentSceneObject = Scene::SceneManager::Instance().getCurrentScene();
			auto sceneActionMap = currentSceneObject->getActionMap();

			// For every desired key, check if it's pressed
			// Trigger an Action if state of key press changes
			for (auto key : sceneActionMap)
			{
				if (App::IsKeyPressed(key.first))
				{
					if (previousKeyStates[key.first] != Events::PRESS)
					{
						currentSceneObject->doAction(Events::Action(key.second, Events::PRESS));
						previousKeyStates[key.first] = Events::PRESS;
					}
				}
				else {
					// Prevent release event from occuring on first frame
					if (previousKeyStates[key.first] == Events::NONE)
					{
						continue;
					}

					if (previousKeyStates[key.first] != Events::RELEASE)
					{
						currentSceneObject->doAction(Events::Action(key.second, Events::RELEASE));
						previousKeyStates[key.first] = Events::RELEASE;
					}
				}
			}

		}

	}
}