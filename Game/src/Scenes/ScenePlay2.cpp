//------------------------------------------------------------------------
// ScenePlay.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "Scenes/ScenePlay2.h"

using namespace MultipixelEngine::Core;
using namespace MultipixelEngine::Events;
using namespace MultipixelEngine::Scene;

namespace Game
{
	std::string b = "";

	ScenePlay2::ScenePlay2()
		: inputMessage(gameObjectManager.createGameObject())
	{
	}

	void ScenePlay2::init()
	{
		registerAction('W', "UP");
		registerAction('S', "DOWN");
		registerAction('A', "LEFT");
		registerAction('D', "RIGHT");

		GameObject e = gameObjectManager.createGameObject();
		e.addComponent<CTransform>();
		e.addComponent<CBoundingBox>();
		e.getComponent<CBoundingBox>().size = Vector2(100, 100);
		e.getComponent<CTransform>().position = Vector2(700, 500);

		inputMessage.addComponent<CTransform>();
		inputMessage.addComponent<UIText>();
		inputMessage.getComponent<CTransform>().position = Vector2(500, 500);
		inputMessage.getComponent<UIText>().text = b;
	}

	void ScenePlay2::update()
	{
		inputMessage.getComponent<UIText>().text = b;
	}

	void ScenePlay2::sPhysics()
	{

	}

	void ScenePlay2::sDoAction(Action action)
	{
		b = action.toString();
		if (action.name() == "UP" && action.type() == PRESS)
		{
			SceneManager::Instance().changeScene(0);
		}
	}
}