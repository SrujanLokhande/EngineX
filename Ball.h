#pragma once
#include "GameObject.h"
#include "CoreMinimal.h"

class CircleRenderComponent;
class Transform;
class PhysicsComponent;
class Ball : public GameObject
{
public:

	Ball(float speed, float mSize);

	void ChangeDirection(const exVector2 newDirection);

private:

	std::shared_ptr<Transform> mTransformComponent;
	std::shared_ptr<CircleRenderComponent> mRenderComponent;
	std::shared_ptr<PhysicsComponent> mPhysicsComponent;

	float mBallSpeed;
	float mSize;
};

