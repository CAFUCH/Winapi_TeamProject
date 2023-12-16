#include "pch.h"
#include "EventMgr.h"
#include "Object.h"
#include "Weapon.h"
#include "StageMgr.h"
#include "SceneMgr.h"
void EventMgr::Update()
{
	/*for (size_t i = 0; i < m_vecObjDead.size(); ++i)
	{
 		delete m_vecObjDead[i];
	}
	m_vecObjDead.clear();*/

	//for (size_t i = 0; i < m_vecWeaDead.size(); ++i)
	//{
	//	delete m_vecWeaDead[i];
	//}
	//m_vecWeaDead.clear();

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void EventMgr::DeleteObject(Object* _pObj)
{
	tEvent eve = {};
	eve.eEve = EVENT_TYPE::DELETE_OBJECT;
	eve.Obj = _pObj;
	m_vecEvent.push_back(eve);

	

	if (_pObj->GetName() == L"Enemy") {
		StageMgr::GetInst()->enemyCountInWave--;
	}
}

void EventMgr::DeleteWeapon(Weapon* _pWea)
{
	tEvent eve = {};
	eve.eEve = EVENT_TYPE::DELETE_OBJECT;
	eve.Wea = _pWea;
	m_vecEvent.push_back(eve);

	if (_pWea->GetName() == L"Bullet") {
		//StageMgr::GetInst()->enemyCountInWave--;
	}
}

void EventMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEve)
	{
	case EVENT_TYPE::DELETE_OBJECT:
	{
		if (_eve.Obj != nullptr)
		{
			Object* pDeadObj = _eve.Obj;
			pDeadObj->SetDead();
			m_vecObjDead.push_back(pDeadObj);

			if (pDeadObj->GetName() == L"Player") {
				SceneMgr::GetInst()->LoadScene(L"GameOver_Scene");
			}
		}
		if (_eve.Wea != nullptr)
		{
			Weapon* pDeadWea = _eve.Wea;
			pDeadWea->SetDead();
			m_vecWeaDead.push_back(pDeadWea);
		}
	}
	break;
	case EVENT_TYPE::CREATE_OBJECT:
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		break;
	}
}
