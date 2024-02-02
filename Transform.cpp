#include "Transform.h"
#include <iostream>

Transform::Transform(exVector2 loc, exVector2 rot, exVector2 scale, std::shared_ptr<GameObject> owner) : Component(owner),
mLocation(loc),
mRotation(rot),
mScale(scale)
{

}

ComponentTypes Transform::GetComponentType() const
{
	return ComponentTypes::Transform;
}

void Transform::BeginPlay()
{
}

void Transform::EndPlay()
{
}

void Transform::Tick()
{
	Component::Tick();
}

exVector2 Transform::GetPosition() const
{
	return mLocation;
}

exVector2 Transform::GetSize() const
{
	return mScale;
}

void Transform::SetPosition(const exVector2& newPosition)
{
	mLocation = newPosition;
}
