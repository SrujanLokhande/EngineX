#pragma once
#include <vector>
#include <memory>
#include "Engine/Public/EngineInterface.h"

#define PHYSICS_ENGINE PhysicsEngine::GetInstance()

class PhysicsComponent;

class PhysicsEngine
{
public:

	static PhysicsEngine* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new PhysicsEngine();
		}
		return sInstance;
	}

	void PhysicsUpdate();
	void AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd);

private:

	PhysicsEngine();

	std::vector<std::shared_ptr<PhysicsComponent>> mPhysicsComponents;
	static PhysicsEngine* sInstance;
};

