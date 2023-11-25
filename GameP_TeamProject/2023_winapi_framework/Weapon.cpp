#include "pch.h"
#include "Weapon.h"

#include "SceneMgr.h"

Weapon::Weapon()
	: m_pTex(nullptr)
	, m_eElementType(ENTITY_ELEMENT_TYPE::NONE)
{
}

Weapon::~Weapon()
{
}
