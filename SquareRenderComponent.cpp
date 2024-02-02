#include "SquareRenderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "RenderingEngine.h"


SquareRenderComponent::SquareRenderComponent(float length, float height, std::shared_ptr<GameObject> owner, exColor color) : RenderComponent(owner, color)
{
	mLength = length;
	mHeight = height;
}

void SquareRenderComponent::Render(exEngineInterface* engineInterface)
{
	RenderComponent::Render(engineInterface);
	if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
	{
		engineInterface->DrawBox(
			transformComp->GetPosition() - exVector2{ mLength / 2, mHeight / 2 },
			transformComp->GetPosition() + exVector2{ mLength / 2, mHeight / 2 },
			mColor, 2);
	}
}

void SquareRenderComponent::BeginPlay()
{
	if (mOwner)
		RENDER_ENGINE->AddRenderingComponent(mOwner->FindComponentOfType<SquareRenderComponent>());
}
