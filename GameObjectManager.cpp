#include "GameObjectManager.h"
#include "GameObject.h"
#include <iostream>

#define GAME_OBJECT_MANAGER GameObjectManager::GetInstance()

GameObjectManager* GameObjectManager::sInstance = nullptr;
GameObjectManager::GameObjectManager()
{

};

void GameObjectManager::Initialize()
{
	for (std::shared_ptr<GameObject> currentGO : mGameObjectList)
	{
		currentGO->BeginPlay();
	}
}

void GameObjectManager::Update()
{
	for (std::shared_ptr<GameObject> currentGO : mGameObjectList)
	{
		currentGO->Tick();
	}
}



