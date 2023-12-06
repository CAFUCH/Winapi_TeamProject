#pragma once
#include "State.h"
class Chase_State_Range :
    public State
{
public:
	Chase_State_Range(AI* _ai, float _speed);
	~Chase_State_Range();

public:
	void Update() override;
	void EnterState() override;
	void ExitState() override;

private:
	AI* ai;
	Enemy* owner;
	float speed;
};

