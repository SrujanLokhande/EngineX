#include "RenderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "RenderingEngine.h"

#include <iostream>

RenderComponent::RenderComponent(std::shared_ptr<GameObject> owner, exColor color /* ={255,255,255,255}*/ ) : Component(owner)
{
    mColor = color;    
}

ComponentTypes RenderComponent::GetComponentType() const
{
    return ComponentTypes::Shape;
}

void RenderComponent::BeginPlay()
{
    if(mOwner)
        RENDER_ENGINE->AddRenderingComponent(shared_from_this());
}

void RenderComponent::EndPlay()
{
}

void RenderComponent::Tick()
{
    Component::Tick();
    //std::cout << "RenderComponent::Tick()" << std::endl;
}

void RenderComponent::Render(exEngineInterface* engineIterface)
{

}
void RenderComponent::RenderBox(exEngineInterface* engineIterface)
{
    if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentOfType<Transform>())
    {
        engineIterface->DrawBox(transformComp->GetPosition(), {10.0f,20.0f}, {255,0,0,255}, 2);
    }
}

void RenderComponent::SetColor(exColor color)
{
    mColor = color;
}
