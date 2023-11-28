#include "pch.h"
#include "Gun.h"
#include "Scene.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Gun::Gun()
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
		GetAnimator()->CreateAnim(L"Weapon_Gun", m_pTex, Vec2(0.f, 0.f),
			Vec2(32.f, 32.f), Vec2(32.f, 0.f), 12, 0.5f);
	}

	m_eElementType = ENTITY_ELEMENT_TYPE::NONE;

	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
	m_pOwner = m_pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);
}

Gun::~Gun()
{
}

void Gun::Update()
{
	Vec2 vPos = GetPos();


}

void Gun::Attack(Vec2 dir)
{
	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)
	GetAnimator()->PlayAnim(L"Weapon_Gun", false);


	//Vec2 vPos = GetPos();
	//// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}