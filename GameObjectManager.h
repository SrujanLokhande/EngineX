#pragma once
#include "GameObject.h"
#include <vector>
#include <memory>
#include <type_traits>
#define GAME_OBJECT_MANAGER GameObjectManager::GetInstance()

class GameObject;

// TO Manage All Game Objects
class GameObjectManager
{

public:

	static GameObjectManager* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new GameObjectManager();
		}
		return sInstance;
	}

	void Initialize();
	void Update();

	template<std::derived_from<GameObject> T, typename... Args>
	std::shared_ptr<T> SpawnGameObject(Args... arguments) 
	{
		std::shared_ptr<T> newObject = std::make_shared<T>(arguments...);
		mGameObjectList.push_back(newObject);
		newObject->BeginPlay();
		return newObject;
	}

private:

	GameObjectManager();

	std::vector<std::shared_ptr<GameObject>> mGameObjectList;
	static GameObjectManager* sInstance;
};



