#include "HomingComponent.h"
#include "GameObject.h"
#include <iostream>
#include "Random.h"
#include "Game/Private/Game.h"
#include "SrujanGavinRandom.h"

#define RANDOM_COLOR static_cast<unsigned char>(SrujanGavinRandom<int>::GetInstance()->SrujanGavinRandomRange(0, 255))
#define RANDOM_INT(X) SrujanGavinRandom<int>::GetInstance()->SrujanGavinRandomRange(0, X)
#define RANDOM_EXVECTOR(X, Y) exVector2(RANDOM_INT(X), RANDOM_INT(Y))

class Transform;
class MyGame;

HomingComponent::HomingComponent(std::shared_ptr<GameObject> owner)
	: Component(owner)
{
}

ComponentTypes HomingComponent::GetComponentType() const
{
	return ComponentTypes::HomingComponent;
}

void HomingComponent::SetToTrack(Transform iWillTrackThisForYou)
{
	mToTrack = std::make_shared<Transform>(iWillTrackThisForYou);
}

void HomingComponent::BeginPlay()
{
}

void HomingComponent::EndPlay()
{
}

void HomingComponent::Tick()
{
	const float MINIMUM_DISTANCE = 15.0f;

	const float homingSpeed = 15.f;

	auto ourTransform = mOwner->FindComponentOfType<Transform>();
	auto trackedPosition = mToTrack->GetPosition();
	auto ourPosition = ourTransform->GetPosition();

	exVector2 v2MeToTarget;
	v2MeToTarget.x = trackedPosition.x - ourPosition.x;
	v2MeToTarget.y = trackedPosition.y - ourPosition.y;

	float fMeToTargetLength = sqrtf(v2MeToTarget.x * v2MeToTarget.x + v2MeToTarget.y * v2MeToTarget.y);

	exVector2 v2Velocity;

	float inverseLength = 1.0f / fMeToTargetLength;

	v2Velocity.x = v2MeToTarget.x * inverseLength;
	v2Velocity.y = v2MeToTarget.y * inverseLength;

	v2Velocity.x *= homingSpeed;
	v2Velocity.y *= homingSpeed;

	ourTransform->SetPosition(exVector2{ ourPosition.x + v2Velocity.x, ourPosition.y + v2Velocity.y });


	if (fMeToTargetLength < MINIMUM_DISTANCE)
	{
		auto trackingOwner = mToTrack->GetOwner();
		trackingOwner->FindComponentOfType<RenderComponent>()->SetColor({RANDOM_COLOR, RANDOM_COLOR, RANDOM_COLOR, 255});
		trackingOwner->FindComponentOfType<Transform>()->SetPosition(RANDOM_EXVECTOR(800, 600));

		//MyGame::mCurrentGame->AddExplosion(ourPosition);

		MyGame::mPoints++;
	}
}