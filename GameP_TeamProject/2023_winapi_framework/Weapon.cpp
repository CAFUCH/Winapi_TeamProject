#include "pch.h"
#include "Weapon.h"

Weapon::Weapon()
	: m_pTex(nullptr)
	, m_eElementType(ENTITY_ELEMENT_TYPE::NONE)
{
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
}

void Weapon::Render(HDC _dc)
{
}

void Weapon::Attack(Vec2 dir)
{
}
