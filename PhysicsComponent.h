#pragma once
#include "Component.h"
#include "RenderComponent.h"
#include <functional>
#include <vector>


typedef std::function<void(exVector2)> CollisionEventSignature;
class PhysicsEngine;
class Transform;

class PhysicsComponent :  public Component , public std::enable_shared_from_this<PhysicsComponent>
{
	friend class PhysicsEngine;

public:

	PhysicsComponent() = delete;
	PhysicsComponent(std::shared_ptr<GameObject> owner);

	void SetRandomPosition();

	virtual ComponentTypes GetComponentType() const;

	// Game Event Functions
	virtual void BeginPlay();
	virtual void EndPlay();

	virtual void Tick();

	virtual void Physics();

	virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent);			// detect collision with other componenet

	void ListenToCollision(CollisionEventSignature delegateToAdd);
	void StopListeningToCollision(CollisionEventSignature delegateToRemove);
	void SetRenderComponent(std::shared_ptr<RenderComponent> renderComponent);
	std::shared_ptr<RenderComponent> GetRenderComponent() const;
	std::shared_ptr<Transform> GetTransform() const;

	void SetVelocity(const exVector2 inVelocity);

	bool mCanCollide;

protected:

	bool mIsStatic;
	bool mIsGravityEnabled;
	exVector2 mVelocity;
	float mouseX, mouseY;
	

private:
	
	std::vector<CollisionEventSignature> mCollisionEvents;
	std::shared_ptr<RenderComponent> mRenderComponent;

};

