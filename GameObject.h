#pragma once
#include "Component.h"
#include "CoreMinimal.h"
#include "CircleRenderComponent.h"
#include "MouseTrackingComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "SquareRenderComponent.h"
#include <type_traits>

class GameObject : public std::enable_shared_from_this<GameObject>
{

public:

	GameObject();
	~GameObject();

	// Game Event Functions
	virtual void Initialize();
	virtual void BeginPlay();
	virtual void EndPlay();
	virtual void Tick();

	template<class T = Component >
	std::shared_ptr<T> FindComponentOfType()
	{
		for (std::shared_ptr<Component> componentIter : mComponents)
		{
			if (std::shared_ptr<T> castedComponent = std::dynamic_pointer_cast<T>(componentIter))
			{
				return castedComponent;
			}
		}
		return nullptr;
	};

	template<class T = Component >
	bool HasComponentOfType()
	{
		for (std::shared_ptr<Component> componentIter : mComponents)
		{
			if (std::shared_ptr<T> castedComponent = std::dynamic_pointer_cast<T>(componentIter))
			{
				return true;
			}
		}
		return false;
	};

	// Component Helper Functions

	// C++ 20 syantax std::derived_from<class to derive from>
	// typename... Args -> varadic arguments
	// we can use class T also if we use older c++
	template<std::derived_from<Component> T ,typename... Args>													// this is a varadic argument which lets to add as many params as we want
	std::shared_ptr<T> AddComponent(Args... arguments)
	{
		std::shared_ptr<T> componentToAdd = std::make_shared<T>(arguments..., shared_from_this());
		mComponents.push_back(componentToAdd);			
		componentToAdd->BeginPlay();		
		return componentToAdd;
	}

	void RemoveComponent(std::shared_ptr<Component> componentToRemove);

private:

	ComponentList mComponents;
};


