#include "pch.h"
#include "Weapon.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"

#include "Texture.h"
#include "Collider.h"

Weapon::Weapon()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"", L"");
}

Weapon::~Weapon()
{
}

void Weapon::Attack(Vec2 dir)
{
	// 테스트용, h가서 abs로 바꿔줄 것.
	
	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)

	
	Vec2 vPos = GetPos();
	// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	vPos.x += dir.x * m_fSpeed * fDT;
}
