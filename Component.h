#pragma once
#include "CoreMinimal.h"

enum class ComponentTypes
{
	Transform,
	Physics,
	Shape,
	BoxShape,
	CircleShape,
	MouseTracking,
	StateMachine,
	HomingComponent,
};

// Forward Declaration
class GameObject;

class Component
{
public:
	Component(std::shared_ptr<GameObject> owner);
	virtual ~Component() {};

	virtual ComponentTypes GetComponentType() const  = 0;
	
	// Game Event Functions
	virtual void BeginPlay() = 0;
	virtual void EndPlay() = 0;

	virtual void Tick();

	virtual void SetOwner(std::shared_ptr<GameObject> owner);

	virtual std::shared_ptr<GameObject> GetOwner();

protected:
	std::shared_ptr<GameObject> mOwner;
};

typedef std::vector<std::shared_ptr<Component>> ComponentList;