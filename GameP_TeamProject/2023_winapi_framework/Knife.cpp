#include "pch.h"
#include "Knife.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"

Knife::Knife()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"", L"");
}

Knife::~Knife()
{
}

void Knife::Attack(Vec2 dir)
{
	// if (공격 쿨타임이 지났다면)
	// m_texture 이동 (공격 거리만큼 공격 속도로)


	Vec2 vPos = GetPos();
	// 기본적으로 조준한 방향으로 공속을 통해 이동한다... (총알이라는 가정하에 작성함)
	vPos.x += dir.x * m_fAttackSpeed * fDT;
}
