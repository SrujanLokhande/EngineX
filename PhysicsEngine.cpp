#include "PhysicsEngine.h"
#include "PhysicsComponent.h"
#include <iostream>

PhysicsEngine* PhysicsEngine::sInstance = nullptr;

void PhysicsEngine::PhysicsUpdate()
{
	for (std::shared_ptr<PhysicsComponent> componentToPhysics : mPhysicsComponents)
	{
		if (!componentToPhysics->mCanCollide)
			continue;

		componentToPhysics->Physics();
		for (std::shared_ptr<PhysicsComponent> otherPhysicsComp : mPhysicsComponents)
		{
			return;

			if (!otherPhysicsComp->mCanCollide)
				continue;

			if (componentToPhysics->IsCollisionDetected(otherPhysicsComp))
			{
				//std::cout << "Collision is detected" << std::endl;

				for (CollisionEventSignature physicsEvent : componentToPhysics->mCollisionEvents)
				{
					// Calculate the normal
					physicsEvent({});
				
				}
				
				std::cout << "Hi " << std::endl;
			}
		}
	}
}

void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd)
{
	mPhysicsComponents.push_back(componentToAdd);
}

PhysicsEngine::PhysicsEngine()
{

}
