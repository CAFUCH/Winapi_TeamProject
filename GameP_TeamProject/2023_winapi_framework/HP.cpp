#include "pch.h"
#include "HP.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Texture.h"
HP::HP()
	: m_pBackTex(nullptr)
	, m_pFillTex(nullptr)
{
	m_pBackTex = ResMgr::GetInst()->TexLoad(L"PlayerBCHP", L"Texture\\UI-bcHP.bmp");
	m_pFillTex = ResMgr::GetInst()->TexLoad(L"PlayerHP", L"Texture\\UI-fillHP.bmp");

	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
	m_pOwner = m_pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);

	//SetMaxHP(m_pOwner.front()->GetMaxHP());
	//SetMaxHP(m_pOwner[0]->GetMaxHP());
	//SetHP(m_fMaxHP);
}

HP::~HP()
{
}

void HP::Update()
{
	//SetPos({ m_pOwner[0]->GetPos().x
	//	, m_pOwner[0]->GetPos().y - m_pOwner[0]->GetScale().y / 2});
}

void HP::Render(HDC _dc)
{
	// HP Á¤±ÔÈ­
	m_fHPValue = m_pFillTex->GetWidth() / m_fMaxHP;

	// HP back
	BitBlt(_dc
		, (int)(m_vPos.x - m_vScale.x /2)
		, (int)(m_vPos.y - m_vScale.y /2)
		, m_pBackTex->GetWidth(), m_pBackTex->GetHeight()
		, m_pBackTex->GetDC(), 0, 0, SRCCOPY);

	// HP fill
	BitBlt(_dc
		, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_fHPValue * m_fCurHP, m_pFillTex->GetHeight()
		, m_pFillTex->GetDC(), 0, 0, SRCCOPY);
}
