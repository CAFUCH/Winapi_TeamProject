#include "pch.h"
#include "Enemy.h"
#include "AI.h"
#include "Idle_State.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

Idle_State::Idle_State(AI* _ai, float _waitTime)
	: ai(_ai)
	, waitTime(_waitTime)
{
	curTime = 0;
}

Idle_State::~Idle_State()
{
}

void Idle_State::Update()
{
	curTime += fDT;
	if (curTime >= waitTime) {
		ai->ChangeState(ENEMY_STATE::ATTACK);
	}
}

void Idle_State::EnterState()
{
	curTime = 0;
}

void Idle_State::ExitState()
{
}