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
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Guns", L"Texture\\Bullet.bmp");

	//// �ݶ��̴� ����
	//CreateCollider();
	//// �ݶ��̴� ������ �ʱ�ȭ
	//GetCollider()->SetScale(Vec2(50.f, 50.f)); 

	//// �ִϸ����� ����
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
	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)


	//Vec2 vPos = GetPos();
	//// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}
