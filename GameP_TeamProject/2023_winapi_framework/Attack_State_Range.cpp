#include "pch.h"
#include "Attack_State_Range.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Animation.h"
#include "Animator.h"

#include "Object.h"
#include "Core.h"

#include "Enemy_Bullet.h"
#include "SceneMgr.h"

Attack_State_Range::Attack_State_Range(AI* _ai)
	:ai(_ai)
{
	owner = ai->GetOnwer();

	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
}

Attack_State_Range::~Attack_State_Range()
{

}

void Attack_State_Range::Update()
{
	curTime += fDT;
	if (curTime >= waitTime) {
		//°ø°Ý¤¡¤¡
		Vec2 thisPos = owner->GetPos();
		const Player* pObj = owner->GetPlayer();
		Vec2 pPos = pObj->GetPos();

		Vec2 dir = (pPos - thisPos).Normalize();

		Enemy_Bullet* pBullet = new Enemy_Bullet(10.f, 600.f);
		pBullet->SetPos(thisPos);
		pBullet->SetScale(Vec2(25.f, 25.f));
		pBullet->SetDir(dir);
		SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);


		owner->GetDamage();

		ai->ChangeState(ENEMY_STATE::CHASE);

		//if (pPos.Distance(thisPos, pPos) > 300.f) {
		//	
		//}
		//else
		//{
		//	ai->ChangeState(ENEMY_STATE::IDLE);
		//}
	}
}

void Attack_State_Range::EnterState()
{
	curTime = 0;
}

void Attack_State_Range::ExitState()
{
}
