#include "MouseTrackingComponent.h"
#include "GameObject.h"
#include "Transform.h"

#include <iostream>

MouseTrackingComponent::MouseTrackingComponent(std::shared_ptr<GameObject> owner)
    : Component(owner)
    , mMouseX(0)
    , mMouseY(0)
{
}

ComponentTypes MouseTrackingComponent::GetComponentType() const
{
    return ComponentTypes::MouseTracking;
}

void MouseTrackingComponent::BeginPlay()
{
    // Subscribe to mouse events or perform any necessary initialization
    std::cout<<"MouseTrackingComponent::BeginPlay()"<<std::endl;
}

void MouseTrackingComponent::EndPlay()
{
    // Unsubscribe from mouse events or perform any necessary cleanup
}

void MouseTrackingComponent::Tick()
{
    //std::cout << "MouseTrackingComponent::Tick()" << std::endl;

    if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
    {
        exVector2 newPosition = { static_cast<float>(mMouseX), static_cast<float>(mMouseY) };
        transformComp->SetPosition(newPosition);
    }
}

void MouseTrackingComponent::SetMousePosition(int mouseX, int mouseY)
{
    mMouseX = mouseX;
    mMouseY = mouseY;
}
