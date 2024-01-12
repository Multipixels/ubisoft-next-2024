//---------------------------------------------------------------------------------
// GameObject.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Core/GameObject.h"
#include "Core/GameObjectMemoryPool.h"

namespace MultipixelEngine
{
	namespace Core
	{
		GameObject::GameObject(size_t idIn)
			: gameObjectId(idIn)
		{

		}

		void GameObject::destroy()
		{
			GameObjectMemoryPool::Instance().removeGameObject(gameObjectId);
		}
	}
}