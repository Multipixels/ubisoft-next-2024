//------------------------------------------------------------------------
// ErrorScene.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/ErrorScene.h"
#include "GameEngine.h"

namespace MultipixelEngine
{
	ErrorScene::ErrorScene(std::string message)
		: errorMessage(message)
	{
		init();
	}

	void ErrorScene::init()
	{
		GameObject uiErrorMessage = gameObjectManager.createGameObject();
		uiErrorMessage.addComponent<CTransform>();
		uiErrorMessage.addComponent<UIText>();

		uiErrorMessage.getComponent<CTransform>().position = Vector2(20, 40);
		uiErrorMessage.getComponent<UIText>().text = errorMessage;
	}

	void ErrorScene::update()
	{

	}

	void ErrorScene::sDoAction(Action action)
	{

	};
}