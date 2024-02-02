#include "CollisionDetector.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "Transform.h"

bool CollisionDetector::Intersects(const CollisionDetector& other) const
{
    if (maxPoint.x < other.minPoint.x || minPoint.x > other.maxPoint.x)
        return false;
    // No intersection on the x-axis

    if (maxPoint.y < other.minPoint.y || minPoint.y > other.maxPoint.y)
        return false;
    // No intersection on the y-axis

    return true;  // Intersection detected
}

CollisionDetector CollisionDetector::GetBoundingBox(const Transform& transform)
{
    exVector2 position = transform.GetPosition();
    exVector2 size     = transform.GetSize();

    CollisionDetector boundingBox;
    boundingBox.minPoint = position;
    boundingBox.maxPoint = position + size;

    return boundingBox;
}