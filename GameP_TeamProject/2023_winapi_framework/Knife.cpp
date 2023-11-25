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
	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)


	Vec2 vPos = GetPos();
	// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	vPos.x += dir.x * m_fAttackSpeed * fDT;
}
