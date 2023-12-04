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
	m_pBackTex = ResMgr::GetInst()->TexLoad(L"PlayerBCHP", L"Texture\\UI_HP-BcFill.bmp");
	m_pFillTex = ResMgr::GetInst()->TexLoad(L"PlayerHP", L"Texture\\UI_HP-Fill.bmp");
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
	 TransparentBlt(_dc
		 , (int)(m_vPos.x - m_pBackTex->GetWidth() / 2)
		 , (int)(m_vPos.y - m_vScale.y / 2)
		 , m_pBackTex->GetWidth(), m_pBackTex->GetHeight()
		 , m_pBackTex->GetDC()
		 , 0, 0
		 , m_pBackTex->GetWidth(), m_pBackTex->GetHeight()
		 , RGB(255, 0, 255));

	TransparentBlt(_dc
		, (int)(m_vPos.x - m_pFillTex->GetWidth() / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, (m_pFillTex->GetWidth() / GetMaxHP()) * GetHP()
		, m_pFillTex->GetHeight()
		, m_pFillTex->GetDC()
		,0, 0
		,m_pFillTex->GetWidth(), m_pFillTex->GetHeight()
		, RGB(255, 0, 255));
}
