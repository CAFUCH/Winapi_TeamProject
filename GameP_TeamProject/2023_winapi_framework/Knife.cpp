#include "pch.h"
#include "Knife.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Knife::Knife()
{
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Knife", L"Texture\\Bullet.bmp");

	// 콜라이더 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// 애니메이터 생성
	CreateAnimator();
	/*Knife Animation*/ {
		GetAnimator()->CreateAnim(L"Knife_Attack", m_pTex, Vec2(0.f, 0.f),
			Vec2(64.f, 32.f), Vec2(64.f, 0.f), 12, 0.025f);
		GetAnimator()->PlayAnim(L"Knife_Attack", false);
	}

	m_fDistance = 250.f;
	m_fDelay = 0.3f;
}

Knife::~Knife()
{
}

void Knife::Update()
{
	SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });
	GetAnimator()->Update();
}

void Knife::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Knife::Attack(Vec2 dir)
{
	GetAnimator()->PlayAnim(L"Knife_Attack", false);

	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)


	//Vec2 vPos = GetPos();
	//// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}
