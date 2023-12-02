#include "pch.h"
#include "pch.h"
#include "Chase_State.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
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


	Vec2 thisPos = owner->GetPos();
	Vec2 pPos = owner->GetPlayer()->GetPos();

	Vec2 dir = pPos - thisPos;
	thisPos.x += fDT * speed * dir.x;
	thisPos.y += fDT * speed * dir.y;

	owner->SetPos(thisPos);

	if (KEY_UP(KEY_TYPE::SPACE)) {
		ai->ChangeState(ENEMY_STATE::IDLE);
	}
}

void Chase_State::EnterState()
{

}

void Chase_State::ExitState()
{

}
