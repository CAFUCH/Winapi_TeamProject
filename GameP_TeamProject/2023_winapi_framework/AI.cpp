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

void AI::AddState(ENEMY_STATE _enemyType, State* _state) //���� �߰�
{

	state_maps.insert(_enemyType, _enemyType);
}

State* AI::FindState(ENEMY_STATE _stateType) //������Ʈ�� �������� �ʹٸ�
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
	prevState = curState; //����������Ʈ�� ����ְ�
	prevState->ExitState(); //������

	curState = state; //���罺����Ʈ�� ����ְ�
	curState->EnterState(); //��


}
