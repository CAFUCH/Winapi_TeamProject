#include "pch.h"
#include "Chase_State_Range.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Animation.h"
#include "Animator.h"

#include "Object.h"
Chase_State_Range::Chase_State_Range(AI* _ai, float _speed)
	:ai(_ai)
	, speed(_speed)
{
	owner = ai->GetOnwer();
}

Chase_State_Range::~Chase_State_Range()
{
}

void Chase_State_Range::Update()
{
	Vec2 thisPos = owner->GetPos();
	const Player* pObj = owner->GetPlayer();
	Vec2 pPos = pObj->GetPos();

	Vec2 dir = (pPos - thisPos).Normalize();

	if (pPos.Distance(thisPos, pPos) > (double)5.f) {
		thisPos.x += fDT * speed * dir.x;
		thisPos.y += fDT * speed * dir.y;
	}
	else
	{
		ai->ChangeState(ENEMY_STATE::IDLE);
	}

	if (dir.x > 0) //¿À¸¥ÂÊ
		owner->GetAnimator()->PlayAnim(owner->ANIM_RIGHT_HASH, true);
	else if (dir.x < 0)//¿ÞÂÊ							
		owner->GetAnimator()->PlayAnim(owner->ANIM_LEFT_HASH, true);

	owner->SetPos(thisPos);
}

void Chase_State_Range::EnterState()
{
}

void Chase_State_Range::ExitState()
{
}
