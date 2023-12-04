#include "pch.h"
#include "AI.h"
#include "State.h"
#include"Idle_State.h"
#include"Enemy.h"
AI::AI(Enemy* _onwer)
	:owner(_onwer)
	, curState(nullptr)
	, prevState(nullptr)
{
	owner->SetAI(this);
}

AI::~AI()
{

}

void AI::InitState(ENEMY_STATE _enemyType)
{
	curState = FindState(_enemyType);
}

void AI::AddState(ENEMY_STATE _enemyType, State* _state) //���� �߰�
{
	state_maps.insert({ _enemyType, _state });
}

void AI::UpdateState()
{
	curState->Update();
}

void AI::ChangeState(ENEMY_STATE _stateType)
{
	prevState = curState; //����������Ʈ�� ����ְ�
	prevState->ExitState(); //������

	curState = FindState(_stateType); //���罺����Ʈ�� ����ְ�
	curState->EnterState(); //��
}

State* AI::FindState(ENEMY_STATE _stateType)
{
	map<ENEMY_STATE, State*>::iterator iter = state_maps.find(_stateType);
	if (iter == state_maps.end())
		return nullptr;
	return iter->second;
}
