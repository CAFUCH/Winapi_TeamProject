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
	// �׽�Ʈ��, h���� abs�� �ٲ��� ��.
	
	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)

	
	Vec2 vPos = GetPos();
	// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	vPos.x += dir.x * m_fSpeed * fDT;
}
