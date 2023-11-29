#include "pch.h"
#include "AI.h"
#include "State.h"
#include"Idle_State.h"
AI::AI(Enemy* _onwer)
	:owner(_onwer)
	, curState(nullptr)
	, prevState(nullptr)
{

}

AI::~AI()
{

}

void AI::InitState(ENEMY_STATE _enemyType)
{
	curState = FindState(_enemyType);
}

void AI::AddState(ENEMY_STATE _enemyType, State* _state) //상태 추가
{
	state_maps.insert({ _enemyType, _state });
}

void AI::UpdateState()
{
	curState->Update();
}

void AI::ChangeState(ENEMY_STATE _stateType)
{
	prevState = curState; //이전스테이트를 담아주고
	prevState->ExitState(); //나가줌

	curState = FindState(_stateType); //현재스테이트를 담아주고
	curState->EnterState(); //들어감
}

State* AI::FindState(ENEMY_STATE _stateType)
{
	//if (state_maps.find(_stateType) != state_maps.end())
	return state_maps[_stateType];
}
