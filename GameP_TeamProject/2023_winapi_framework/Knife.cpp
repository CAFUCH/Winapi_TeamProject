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
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Guns", L"Texture\\Bullet.bmp");

	//// 콜라이더 생성
	//CreateCollider();
	//// 콜라이더 사이즈 초기화
	//GetCollider()->SetScale(Vec2(50.f, 50.f)); 

	//// 애니메이터 생성
	//CreateAnimator();

	///*Knife Animation*/ {

	//}
}

Knife::~Knife()
{
}

void Knife::Update()
{
	SetPos({ m_pOwner->GetPos().x, m_pOwner->GetPos().y });
}

void Knife::Render(HDC _dc)
{
	BitBlt(_dc
		, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_pTex->GetWidth(), m_pTex->GetHeight()
		, m_pTex->GetDC()
		, 0, 0, SRCCOPY);
}

void Knife::Attack(Vec2 dir)
{
	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)


	//Vec2 vPos = GetPos();
	//// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}
