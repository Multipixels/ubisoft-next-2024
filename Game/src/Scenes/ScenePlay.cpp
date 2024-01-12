//------------------------------------------------------------------------
// ScenePlay.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "Scenes/ScenePlay.h"

using namespace MultipixelEngine::Core;
using namespace MultipixelEngine::Events;
using namespace MultipixelEngine::Scene;

namespace Game
{
	std::string a = "";


	ScenePlay::ScenePlay()
		: inputMessage(gameObjectManager.createGameObject())
	{
	}

	void ScenePlay::init()
	{
		registerAction('W', "UP");
		registerAction('S', "DOWN");
		registerAction('A', "LEFT");
		registerAction('D', "RIGHT");

		GameObject e = gameObjectManager.createGameObject();
		e.addComponent<CTransform>();
		e.addComponent<CBoundingBox>();
		e.getComponent<CBoundingBox>().size = Vector2(100, 100);
		e.getComponent<CTransform>().position = Vector2(500, 500);

		inputMessage.addComponent<CTransform>();
		inputMessage.addComponent<UIText>();
		inputMessage.getComponent<CTransform>().position = Vector2(500, 500);
		inputMessage.getComponent<UIText>().text = a;
	}

	void ScenePlay::update()
	{
		inputMessage.getComponent<UIText>().text = a;
	}

	void ScenePlay::sPhysics()
	{

	}

	void ScenePlay::sDoAction(Action action)
	{
		a = action.toString();
		if (action.name() == "UP" && action.type() == PRESS)
		{
			SceneManager::Instance().changeScene(1);
		}
	}
}