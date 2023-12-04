#include "pch.h"
#include "HP.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Texture.h"
#include "Object.h"
HP::HP()
	: m_pBackTex(nullptr)
	, m_pFillTex(nullptr)
{
	m_pBackTex = ResMgr::GetInst()->TexLoad(L"PlayerBCHP", L"Texture\\UI-bcHP.bmp");
	m_pFillTex = ResMgr::GetInst()->TexLoad(L"PlayerHP", L"Texture\\UI-fillHP.bmp");
}

HP::~HP()
{
}

void HP::Update()
{

	SetPos({ m_pOwner->GetPos().x, m_pOwner->GetPos().y });

	if (KEY_DOWN(KEY_TYPE::M))
	{
		SetHP(GetHP() - 1);
	}
}

void HP::Render(HDC _dc)
{
	// HP back
	BitBlt(_dc
		, (int)(m_vPos.x - m_pBackTex->GetWidth() / 2)
		, (int)(m_vPos.y - m_vScale.y /2)
		, m_pBackTex->GetWidth(), m_pBackTex->GetHeight()
		, m_pBackTex->GetDC(), 0, 0, SRCCOPY);

	BitBlt(_dc
		, (int)(m_vPos.x - m_pFillTex->GetWidth() / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, (m_pFillTex->GetWidth() / GetMaxHP()) * GetHP()
		, m_pFillTex->GetHeight()
		, m_pFillTex->GetDC(), 0, 0, SRCCOPY);
}
