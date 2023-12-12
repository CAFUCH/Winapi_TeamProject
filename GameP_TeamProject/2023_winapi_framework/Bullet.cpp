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

Bullet::Bullet()
{
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Gun", L"Texture\\gun.bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// �ִϸ����� ����
	CreateAnimator();
	/*Gun Animation*/ {
		GetAnimator()->CreateAnim(L"Gun_Attack", m_pTex, Vec2(0.f, 0.f),
			Vec2(64.f, 32.f), Vec2(64.f, 0.f), 12, 0.025f);
		GetAnimator()->PlayAnim(L"Gun_Attack", false);
	}

	m_fDistance = 500.f;
	m_fDelay = 0.3f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });
	GetAnimator()->Update();
}

void Bullet::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Bullet::Attack(Vec2 dir)
{
	GetAnimator()->PlayAnim(L"Gun_Attack", false);

	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)
	//GetAnimator()->PlayAnim(L"Weapon_Gun", false);

	//Vec2 vPos = GetPos();
	//// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}