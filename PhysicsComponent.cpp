#include "PhysicsComponent.h"
#include "PhysicsEngine.h"
#include "Transform.h"
#include <algorithm>
#include "GameObject.h"
#include "Engine/Public/SDL.h"
#include <iostream>
#include <sstream>
#include "Random.h"
#include "CollisionDetector.h"


PhysicsComponent::PhysicsComponent(std::shared_ptr<GameObject> owner) : Component(owner)
{
	mIsStatic = false;
	mCanCollide = true;
	mIsGravityEnabled = false;
	mCollisionEvents = {};	
	mVelocity = { 0.0f, 0.0f };
}

void PhysicsComponent::SetRandomPosition()
{
	GetTransform()->SetPosition(
		exVector2(
			RandomFloat(0, 500),
			RandomFloat(0, 800)));
}

ComponentTypes PhysicsComponent::GetComponentType() const
{
	return ComponentTypes::Physics;
}

void PhysicsComponent::BeginPlay()
{
	if (mOwner)
	{
		PHYSICS_ENGINE->AddPhysicsComponent(shared_from_this());
	}
}

void PhysicsComponent::EndPlay()
{
}

void PhysicsComponent::Tick()
{
	Component::Tick();	
}

void PhysicsComponent::Physics()
{
	//if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
	//{
	//	exVector2 newPosition = transformComp->GetPosition() + mVelocity;
	//	transformComp->SetPosition(newPosition);
	//}	

}

bool PhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{

	if ((!mCanCollide) || (!otherComponent->mCanCollide))
		return false;
	

	if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
	{
		// Get the bounding box of the current object
		auto thisBoundingBox = CollisionDetector::GetBoundingBox(*transformComp);

		// Get the bounding box of the other object
		if (std::shared_ptr<Transform> otherTransformComp =
			otherComponent->mOwner->FindComponentOfType<Transform>())
		{
			auto otherBoundingBox = CollisionDetector::GetBoundingBox(*otherTransformComp);

			// Perform AABB collision detection
			if (thisBoundingBox.Intersects(otherBoundingBox))
			{				
				return true;
			}
		}
	}

	return false;
}

void PhysicsComponent::ListenToCollision(CollisionEventSignature delegateToAdd)
{
	mCollisionEvents.push_back(delegateToAdd);
}

void PhysicsComponent::StopListeningToCollision(CollisionEventSignature delegateToRemove)
{
	//std::erase(mCollisionEvents, delegateToRemove);
}

void PhysicsComponent::SetRenderComponent(std::shared_ptr<RenderComponent> renderComponent)
{
	mRenderComponent = renderComponent;
}
std::shared_ptr<RenderComponent> PhysicsComponent::GetRenderComponent() const
{
	return mOwner->FindComponentOfType<RenderComponent>();
}

std::shared_ptr<Transform> PhysicsComponent::GetTransform() const
{
	return mOwner->FindComponentOfType<Transform>();
}

void PhysicsComponent::SetVelocity(const exVector2 inVelocity)
{
	mVelocity = inVelocity;
}

