#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
public:
    Bullet(exEngineInterface * pEngine, const exVector2 & position, const exVector2 & target);

private:
    exEngineInterface* mEngine;
    
};

