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
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Knife", L"Texture\\Knife.bmp");

	// 콜라이더 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// 애니메이터 생성
	CreateAnimator();
	GetAnimator()->CreateAnim(L"Knife", m_pTex, Vec2(0.f, 0.f),
		Vec2(64.f, 64.f), Vec2(1.f, 0.f), 1, 1.f);

	

	m_fDistance = 250.f;
	m_fDelay = 0.3f;
	m_fAtkTime = 1.f;
	m_fCurTime = 0.f;
	//m_vDir = Vec2(0, 0);
	m_IsAtking = false;

	SetName(L"Knife");
	SetScale(Vec2{ 30.f,30.f });
}

Knife::~Knife()
{

}

void Knife::Update()
{
	GetAnimator()->PlayAnim(L"Knife", true);
	Vec2 pPos = GetPos();


	if (m_IsAtking) {

		m_fCurTime += fDT;

		if (m_fCurTime >= m_fAtkTime) {
			m_fCurTime = 0.f;
			m_IsAtking = false;
		}
		else {
			if ((float)pPos.Distance(pPos, m_vDir) > .05f) {

				Vec2 dir = (m_vDir - pPos).Normalize();
				pPos.x += dir.x * m_fCurTime;
				pPos.y += dir.y * m_fCurTime;

				SetPos(pPos);
			}
		}
	}
	else
	{
		SetPos({ m_pOwner->GetPos().x + 100, m_pOwner->GetPos().y });

		//GetCollider()->SetFinalPos({ m_pOwner->GetPos().x + 100, m_pOwner->GetPos().y });
	}
}

void Knife::Render(HDC _dc)
{
	/*TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_pTex->GetWidth() * (m_vScale.x / 100)
		, m_pTex->GetHeight() * (m_vScale.y / 100)
		, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
		, m_pTex->GetHeight(), RGB(255, 0, 255));*/

	Component_Render(_dc);
}

void Knife::EnterCollision(Collider* _pOther)
{
}

void Knife::ExitCollision(Collider* _pOther)
{
}

void Knife::StayCollision(Collider* _pOther)
{
}

void Knife::Attack(Vec2 dir)
{
	GetAnimator()->PlayAnim(L"Knife_Attack", false);
	m_vDir = dir;
	m_IsAtking = true;
	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)


	//Vec2 vPos = GetPos();
	//// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}