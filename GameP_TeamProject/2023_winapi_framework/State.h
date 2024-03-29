#pragma once
class AI;
class Enemy;
class State
{
public:
	State() = default;
	virtual ~State() = default;

public:
	virtual void Update() abstract;
	virtual void EnterState() abstract;
	virtual void ExitState() abstract;

public:

private:
	ENEMY_STATE m_eState;
	//AI* m_pAI;
	//Enemy* owner;
};
