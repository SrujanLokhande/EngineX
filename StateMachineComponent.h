#pragma once
#include "Component.h"
#include "State.h"

class StateMachineComponent : public Component
{
public:

	StateMachineComponent() = delete;
	StateMachineComponent(StateTypes startingState, std::shared_ptr<GameObject> owner);

	virtual ComponentTypes GetComponentType() const;

	// Game Event Functions
	virtual void BeginPlay();
	virtual void EndPlay();

	virtual void Tick();

private:
	std::shared_ptr<State> mCurrentState;

	std::vector<std::shared_ptr<State>> mStates;

	std::shared_ptr<State> GetStateOfType(const StateTypes typeToFind);

	float mTimer;
};

