//---------------------------------------------------------------------------------
// Action.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Actions/Action.h"

namespace GameEngine 
{
	namespace Actions
	{
		Action::Action(const std::string& nameIn, const ActionType typeIn)
			: actionName(nameIn), actionType(typeIn)
		{
		}

		const std::string& Action::name() const
		{
			return actionName;
		}

		const ActionType Action::type() const
		{
			return actionType;
		}

		std::string Action::toString() const
		{
			switch(actionType)
			{
				case NONE: return (actionName + " None");
				case PRESS: return (actionName + " Press");
				case RELEASE: return (actionName + " Release");
			}
		}
	}
}