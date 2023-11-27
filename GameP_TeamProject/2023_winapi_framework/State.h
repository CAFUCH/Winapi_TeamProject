#pragma once
class AI;
class State
{
public:
	State();
	virtual ~State();

public:
	virtual void Update() abstract;
	virtual void EnterState() abstract;
	virtual void ExitState() abstract;

public:
	void SetAI(AI* _ai) { m_pAI = _ai; }

	const ENEMY_STATE& GetType() const { return m_eState; }
	AI* GetAI() const { return m_pAI; }

private:
	ENEMY_STATE m_eState;
	AI* m_pAI;
	friend class AI;
};