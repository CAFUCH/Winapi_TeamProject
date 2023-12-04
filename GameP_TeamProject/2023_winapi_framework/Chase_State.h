#pragma once
#include "State.h"
class Chase_State :
	public State
{
public:
	Chase_State(AI* _ai, float _speed);
	~Chase_State();

public:
	void Update() override;
	void EnterState() override;
	void ExitState() override;

private:
	AI* ai;
	Enemy* owner;
	float speed;
	bool filpX;
};

