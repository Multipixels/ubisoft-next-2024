//---------------------------------------------------------------------------------
// Action.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Events/Action.h"

namespace MultipixelEngine 
{
	namespace Events
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