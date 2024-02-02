#pragma once

#include "Component.h"

class MouseTrackingComponent : public Component
{
public:
    MouseTrackingComponent(std::shared_ptr<GameObject> owner);

    virtual ComponentTypes GetComponentType() const override;
    virtual void BeginPlay() override;
    virtual void EndPlay() override;
    virtual void Tick() override;

    void SetMousePosition(int mouseX, int mouseY);

private:
    int mMouseX;
    int mMouseY;
};
