#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "Weapon.h"
#include "SelectGDI.h"
#include "Camera.h"

UINT Collider::m_sNextID = 0;

Collider::Collider()
	: m_pObjOwner(nullptr)
	, m_pWeaOwner(nullptr)
	, m_vScale(Vec2(40.f,40.f))
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
}

Collider::Collider(const Collider& _origin)
	: m_pObjOwner(nullptr)
	, m_pWeaOwner(nullptr)
	, m_vScale(_origin.m_vScale)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
}

Collider::~Collider()
{}

void Collider::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_check)
		ePen = PEN_TYPE::RED;
	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);
	m_vFinalPos = Camera::GetInst()->GetRenderPos(m_vFinalPos);
	RECT_RENDER(m_vFinalPos.x, m_vFinalPos.y, m_vScale.x, m_vScale.y, _dc);
}

void Collider::EnterCollision(Collider* _pOther)
{
 	++m_check;

	if (m_pObjOwner != nullptr)
		m_pObjOwner->EnterCollision(_pOther);
	if (m_pWeaOwner != nullptr)
		m_pWeaOwner->EnterCollision(_pOther);
}

void Collider::ExitCollision(Collider* _pOther)
{
	--m_check;

	if (m_pObjOwner != nullptr)
		m_pObjOwner->ExitCollision(_pOther);
	if (m_pWeaOwner != nullptr)
		m_pWeaOwner->ExitCollision(_pOther);
}

void Collider::StayCollision(Collider* _pOther)
{
	if (m_pObjOwner != nullptr)
		m_pObjOwner->StayCollision(_pOther);
	if (m_pWeaOwner != nullptr)
		m_pWeaOwner->StayCollision(_pOther);
}

void Collider::FinalUpdate()
{
	// Object위치를 따라가야 하는거야.
	Vec2 vObjPos;
	if (m_pObjOwner != nullptr)
		vObjPos = m_pObjOwner->GetPos();
	if (m_pWeaOwner != nullptr)
		vObjPos = m_pWeaOwner->GetPos();

	m_vFinalPos = vObjPos + m_vOffsetPos;
}

