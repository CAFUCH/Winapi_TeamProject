#include "pch.h"
#include "Chase_State_Melee.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Animation.h"
#include "Animator.h"

#include "Object.h"

Chase_State_Melee::Chase_State_Melee(AI* _ai, float _speed)
	:ai(_ai)
	, speed(_speed)
{
	owner = ai->GetOnwer();
}

Chase_State_Melee::~Chase_State_Melee()
{

}

void Chase_State_Melee::Update()
{
	Vec2 thisPos = owner->GetPos();
	const Player* pObj = owner->GetPlayer();
	Vec2 pPos = pObj->GetPos(); //이거 안됌 

	Vec2 dir = (pPos - thisPos).Normalize();

	if (pPos.Distance(thisPos, pPos) > (double).3f) {
		thisPos.x += fDT * speed * dir.x;
		thisPos.y += fDT * speed * dir.y;
	}

	if (dir.x > 0) //오른쪽
		owner->GetAnimator()->PlayAnim(owner->ANIM_RIGHT_HASH, true);
	else if (dir.x < 0)//왼쪽							
		owner->GetAnimator()->PlayAnim(owner->ANIM_LEFT_HASH, true);

	owner->SetPos(thisPos);
}

void Chase_State_Melee::EnterState()
{

}

void Chase_State_Melee::ExitState()
{

}
