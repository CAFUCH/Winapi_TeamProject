#pragma once
#include "State.h"
class Idle_State :
	public State
{
public:
	Idle_State(AI* _ai);
	~Idle_State();

public:
	virtual void Update() override;
	virtual void EnterState() override;
	virtual void ExitState() override;

private:
	AI* ai;
	float waitTime;
	float m_fMaxDis;
	//sf::Clock m_clock;
};
