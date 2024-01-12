//---------------------------------------------------------------------------------
// EventManager.h
//---------------------------------------------------------------------------------
#pragma once

#include <map>

#include "Action.h"

namespace MultipixelEngine
{
	namespace Events
	{
		class EventManager
		{
			std::map<int, Events::ActionType> previousKeyStates;

			EventManager();

		public:
			static EventManager& Instance()
			{
				static EventManager eventManager;
				return eventManager;
			}

			void registerAction(int actionKey);
			void detectEvent();
		};
	}
}