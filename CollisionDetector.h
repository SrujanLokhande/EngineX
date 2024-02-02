#pragma once
#include "Transform.h"

class CollisionDetector
{
public:

    bool Intersects(const CollisionDetector& other) const;
    static CollisionDetector GetBoundingBox(const Transform& transform);

private:

    exVector2 minPoint;  // Minimum point (bottom-left corner)
    exVector2 maxPoint;  // Maximum point (top-right corner)
};
