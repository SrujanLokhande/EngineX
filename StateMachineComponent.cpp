#include "StateMachineComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"

StateMachineComponent::StateMachineComponent(StateTypes startingState, std::shared_ptr<GameObject> owner) : Component(owner)
{
	mTimer = 0.0f;

	// green State
	mStates.push_back(std::make_shared<State>(StateTypes::Red));
	mStates.push_back(std::make_shared<State>(StateTypes::Yellow));
	mStates.push_back(std::make_shared<State>(StateTypes::Green));

	mCurrentState = GetStateOfType(startingState);
	mCurrentState->EnterState();
	
}

ComponentTypes StateMachineComponent::GetComponentType() const
{
	return ComponentTypes::StateMachine;
}

void StateMachineComponent::BeginPlay()
{

}

void StateMachineComponent::EndPlay()
{
	mStates.clear();
}

void StateMachineComponent::Tick()
{
	if (!mCurrentState)
	{
		return;
	}

	mTimer += 0.5f;

	switch (mCurrentState->GetState())
	{
		case StateTypes::Red:
		{
			if (std::shared_ptr<RenderComponent> renderComp = mOwner->FindComponentOfType<RenderComponent>())
			{
				mCurrentState->RunState();
				renderComp->SetColor({ 255,0,0,255 });
			}
			if (mTimer > 30)
			{
				mCurrentState->EndState();
				mCurrentState = GetStateOfType(StateTypes::Yellow);
				mCurrentState->EnterState();
				mTimer = 0.0f;
			}
		}

		break;

		case StateTypes::Green:
		{
			if (std::shared_ptr<RenderComponent> renderComp = mOwner->FindComponentOfType<RenderComponent>())
			{
				mCurrentState->RunState();
				renderComp->SetColor({ 0,255,0,255 });
			}
			if (mTimer > 30)
			{
				mCurrentState->EndState();
				mCurrentState = GetStateOfType(StateTypes::Red);
				mCurrentState->EnterState();
				mTimer = 0.0f;
			}
		}
		break;	
		
		case StateTypes::Yellow:
		{
			if (std::shared_ptr<RenderComponent> renderComp = mOwner->FindComponentOfType<RenderComponent>())
			{
				mCurrentState->RunState();
				renderComp->SetColor({ 255,255,0,255 });
			}
			if (mTimer > 30)
			{
				mCurrentState->EndState();
				mCurrentState = GetStateOfType(StateTypes::Green);
				mCurrentState->EnterState();
				mTimer = 0.0f;
			}
		}
		break;

	default:
		{
			mCurrentState = GetStateOfType(StateTypes::Green);
			mCurrentState->EnterState();
			mTimer = 0.0f;
		}
		break;
	}
}

std::shared_ptr<State> StateMachineComponent::GetStateOfType(const StateTypes typeToFind)
{
	for (std::shared_ptr<State> iter : mStates)
	{
		if (iter->GetState() == typeToFind)
		{
			return iter;
		}
	}
	return nullptr;
}
