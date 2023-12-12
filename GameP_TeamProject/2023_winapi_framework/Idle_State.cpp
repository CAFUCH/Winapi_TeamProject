#include "pch.h"
#include "Enemy.h"
#include "AI.h"
#include "Idle_State.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Animation.h"
#include "Animator.h"
Idle_State::Idle_State(AI* _ai, float _waitTime)
	: ai(_ai)
	, waitTime(_waitTime)
{
	curTime = 0;
	owner = ai->GetOnwer();
}

Idle_State::~Idle_State()
{
}

void Idle_State::Update()
{
	Vec2 thisPos = owner->GetPos();
	const Player* pObj = owner->GetPlayer();
	Vec2 pPos = pObj->GetPos();

	Vec2 dir = (pPos - thisPos).Normalize();

	if (dir.x > 0)
		owner->GetAnimator()->PlayAnim(owner->ANIM_RIGHT_IDLE_HASH, true);
	else if(dir.x < 0)
		owner->GetAnimator()->PlayAnim(owner->ANIM_LEFT_IDLE_HASH, true);

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