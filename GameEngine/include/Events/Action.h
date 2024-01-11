//---------------------------------------------------------------------------------
// Action.h
//---------------------------------------------------------------------------------
#pragma once

#include <string>

namespace MultipixelEngine 
{
	namespace Events 
	{
		enum ActionType { NONE, PRESS, RELEASE };

		class Action
		{
			std::string actionName = "NONE";
			ActionType actionType = NONE;
		public:
			Action() = default;
			Action(const std::string& nameIn, const ActionType typeIn);

			const std::string& name() const;
			const ActionType type() const;
			std::string toString() const;
		};
	}
}