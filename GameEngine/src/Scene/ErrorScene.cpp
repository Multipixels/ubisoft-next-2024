//------------------------------------------------------------------------
// ErrorScene.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "App/app.h"
#include "Scene/ErrorScene.h"

namespace MultipixelEngine
{
	ErrorScene::ErrorScene(std::string message)
		: errorMessage(message)
	{
		
	}

	void ErrorScene::init()
	{
	}

	void ErrorScene::update()
	{

	}

	void ErrorScene::sDoAction(Action action)
	{

	};

	void ErrorScene::sRender()
	{
		App::Print(20, 40, "Error", 1, 1, 1);
		App::Print(20, 20, errorMessage.c_str(), 1, 1, 1);
	}
}