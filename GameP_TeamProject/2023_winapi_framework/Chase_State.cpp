#include "pch.h"
#include "Chase_State.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
Chase_State::Chase_State(AI* _ai, float _speed)
	:ai(_ai)
	, speed(_speed)
{
	owner = ai->GetOnwer();
}

Chase_State::~Chase_State()
{

}

void Chase_State::Update()
{

}

void Chase_State::EnterState()
{

}

void Chase_State::ExitState()
{

}
