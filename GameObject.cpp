#include "GameObject.h"
#include "GameObjectManager.h"
#include "Component.h"

#include <iostream>

GameObject::GameObject()
{
	//GAME_OBJECT_MANAGER->AddGameObject(this);
}

GameObject::~GameObject()
{
}

void GameObject::Initialize()
{
	std::shared_ptr<GameObject> sharedThis = shared_from_this();	
}

void GameObject::BeginPlay()
{
	for (std::shared_ptr<Component> componetIter : mComponents)
	{
		componetIter->BeginPlay();
	}
}

void GameObject::EndPlay()
{
	for (std::shared_ptr<Component> componetIter : mComponents)
	{
		componetIter->EndPlay();
	}
}

void GameObject::Tick()
{
	//std::cout << "GameObject::Tick()" << std::endl;

	for (std::shared_ptr<Component> componetIter : mComponents)
	{
		//std::cout << "std::shared_ptr<Component> componetIter : mComponents" << std::endl;

		componetIter->Tick();
	}
}


void GameObject::RemoveComponent(std::shared_ptr<Component> componentToRemove)
{
	auto iterBegin = mComponents.begin();
	auto iterEnd = mComponents.end();

	while (iterBegin != iterEnd)
	{
		if (*iterBegin == componentToRemove)
		{
			mComponents.erase(iterBegin);
		}
		++iterBegin;
	}
}
