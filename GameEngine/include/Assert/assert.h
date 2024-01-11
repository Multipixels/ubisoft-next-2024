#pragma once

#include <cassert>

#include "Scene/ErrorScene.h"

//-------------------------------------------------------------------------------------------
// #define ASSERT(condition, message, ...)
//-------------------------------------------------------------------------------------------
// Custom assert for the MultipixelEngine. If condition fails, an Error scene will pop up
// with the error message provided.
//-------------------------------------------------------------------------------------------
#define ASSERT(condition, message, ...) \
	if(!condition) \
	{ \
		MultipixelEngine::GameEngine::Instance().crash(message); \
	} \