#pragma once
#include "State.h"
class Attack_State_Range :
    public State
{
public:
	Attack_State_Range(AI* _ai);
	~Attack_State_Range();

public:
	void Update() override;
	void EnterState() override;
	void ExitState() override;

private:
	AI* ai;
	Enemy* owner;
	float waitTime;
	float curTime;
};

