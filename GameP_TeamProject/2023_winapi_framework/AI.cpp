#include "pch.h"
#include "AI.h"
#include "State.h"

AI::AI(Enemy* _onwer)
	:owner(_onwer)
	, curState(nullptr)
	, prevState(nullptr)
{
}

AI::~AI()
{

}

void AI::AddState(ENEMY_STATE _enemyType, State* _state) //상태 추가
{

	state_maps.insert(_enemyType, _enemyType);
}

State* AI::FindState(ENEMY_STATE _stateType) //스테이트를 가져오고 싶다면
{
	//if (state_maps.find(_stateType) != state_maps.end())
	return state_maps[_stateType];
}

void AI::UpdateState()
{
	curState->Update();
}

void AI::ChangeState(State* state)
{
	prevState = curState; //이전스테이트를 담아주고
	prevState->ExitState(); //나가줌

	curState = state; //현재스테이트를 담아주고
	curState->EnterState(); //들어감


}
