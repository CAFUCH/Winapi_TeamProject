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
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Knife", L"Texture\\Bullet.bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// �ִϸ����� ����
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

	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)


	//Vec2 vPos = GetPos();
	//// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}
