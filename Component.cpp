#include "Component.h"

Component::Component(std::shared_ptr<GameObject> owner)
{
	mOwner = owner;
}

void Component::Tick()
{
}

void Component::SetOwner(std::shared_ptr<GameObject> owner)
{
	mOwner = owner;
}

std::shared_ptr<GameObject> Component::GetOwner()
{
	return mOwner;
}
