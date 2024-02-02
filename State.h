#pragma once

enum class StateTypes
{
	Default,
	Red,
	Yellow,
	Green
};

class State
{
public:

	State(StateTypes inType) : mStateType(inType) 
	{};
	void EnterState();
	void RunState();
	void EndState();

	StateTypes GetState() const
	{
		return mStateType;
	}

private:
	StateTypes mStateType;
};

inline void State::EnterState()
{
}

inline void State::RunState()
{
}

inline void State::EndState()
{
}
