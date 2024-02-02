#include "CircleRenderComponent.h"
#include "GameObject.h"
#include "Transform.h"

CircleRenderComponent::CircleRenderComponent(float radius, std::shared_ptr<GameObject> owner, exColor color /*= { 255,0,0,255 }*/) : RenderComponent(owner, color)
{
	mRadius = radius;
}

void CircleRenderComponent::Render(exEngineInterface* engineInterface)
{
    RenderComponent::Render(engineInterface);
    if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
    {
        engineInterface->DrawCircle(transformComp->GetPosition(), mRadius, mColor, 2);
    }
}

exColor CircleRenderComponent::GetColor() const
{
    return mColor;
}
