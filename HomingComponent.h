#pragma once
#include "Component.h"
#include "Transform.h"
#include <memory>

class HomingComponent :
    public Component
{
public:

    HomingComponent() = delete;

    HomingComponent(std::shared_ptr<GameObject> owner);

    virtual ComponentTypes GetComponentType() const;

    void SetToTrack(Transform iWillTrackThisForYou);

    std::shared_ptr <Transform> mToTrack;

    virtual void BeginPlay();
    virtual void EndPlay();

    virtual void Tick();
};

