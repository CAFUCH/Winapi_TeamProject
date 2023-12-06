#include "pch.h"
#include "Gun.h"
#include "Scene.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Gun::Gun()
{
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Gun", L"Texture\\planem.bmp");

	//// 콜라이더 생성
	//CreateCollider();
	//// 콜라이더 사이즈 초기화
	//GetCollider()->SetScale(Vec2(50.f, 50.f));

	//// 애니메이터 생성
	//CreateAnimator();
	///*Gun Animation*/ {
	//	GetAnimator()->CreateAnim(L"Gun_Attack", m_pTex, Vec2(0.f, 0.f),
	//		Vec2(32.f, 32.f), Vec2(32.f, 0.f), 12, 5.f);
	//}

	m_fDistance = 1000.f;

	//m_pCurScene = SceneMgr::GetInst()->GetCurScene();
	//m_pOwner = m_pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);

}

Gun::~Gun()
{
}

void Gun::Update()
{
	SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });

	////if (KEY_UP(KEY_TYPE::O))
	//	GetAnimator()->PlayAnim(L"Gun_Attack", true);

	//SetPos({ m_pOwner->GetPos().x, m_pOwner->GetPos().y });
}

void Gun::Render(HDC _dc)
{
	BitBlt(_dc
		, (int)(GetPos().x - m_vScale.x / 2)
		, (int)(GetPos().y - m_vScale.y / 2)
		, m_pTex->GetWidth(), m_pTex->GetHeight()
		, m_pTex->GetDC()
		, 0, 0, SRCCOPY);
}

void Gun::Attack(Vec2 dir)
{
	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)
	//GetAnimator()->PlayAnim(L"Weapon_Gun", false);


	//Vec2 vPos = GetPos();
	//// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}