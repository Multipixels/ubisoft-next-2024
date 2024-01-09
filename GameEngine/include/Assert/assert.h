#pragma once

#include <cassert>

#include "GameEngineManager.h"
#include "Scene/ErrorScene.h"

#define ASSERT(condition, message, ...) \
	if(!condition) \
	{ \
		GameEngine::GameEngineManager::Instance().crash(message); \
	} \