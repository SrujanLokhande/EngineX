#include "Ball.h"
#include "Transform.h"
#include "CircleRenderComponent.h"
#include "PhysicsComponent.h"

Ball::Ball(float speed, float size) : mBallSpeed(speed), mSize(size)
{
	exVector2 startPosition{250.0f, 250.0f};
	mTransformComponent = AddComponent<Transform>(startPosition, startPosition, startPosition);	
	mRenderComponent = AddComponent<CircleRenderComponent>(150.0f);
	mPhysicsComponent = AddComponent<PhysicsComponent>();

	mPhysicsComponent->SetVelocity({ mBallSpeed, 0.0f });

}

void Ball::ChangeDirection(const exVector2 newDirection)
{
	if (mPhysicsComponent)
	{
		mPhysicsComponent->SetVelocity(newDirection);
	}
}
