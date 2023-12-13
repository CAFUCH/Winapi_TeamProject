#include "pch.h"
#include "Gun.h"
#include "Bullet.h"
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

Gun::~Gun()
{
}

void Gun::Update()
{
	SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });
	GetAnimator()->Update();

	for (Bullet* bullet : bullets)
	{
		if (bullet != nullptr)
			bullet->Update();
	}
}

void Gun::Render(HDC _dc)
{
	for (Bullet* bullet : bullets)
	{
		if (bullet != nullptr)
			bullet->Render(_dc);
	}

	Component_Render(_dc);
}

void Gun::Attack(Vec2 dir)
{
	GetAnimator()->PlayAnim(L"Gun_Attack", false);
	bullets.push_back(new Bullet(L"Bullet", dir
		, { GetPos().x , GetPos().y }
		, { 100, 100 }));
}