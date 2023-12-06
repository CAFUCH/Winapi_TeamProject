#pragma once
#include "State.h"
class Chase_State_Melee :
	public State
{
public:
	Chase_State_Melee(AI* _ai, float _speed);
	~Chase_State_Melee();

public:
	void Update() override;
	void EnterState() override;
	void ExitState() override;

private:
	AI* ai;
	Enemy* owner;
	float speed;
};

