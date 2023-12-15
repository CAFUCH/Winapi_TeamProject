#pragma once
#include "UI.h"
#include "Scene.h"
class Weapon;
class Player;
class Game_Scene :
	public Scene
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	virtual void Release() override;

public:
	static void SetActive_Panel(bool value)
	{
		for (int i = 0; i < Game_Scene::m_ui.size(); ++i) {
			Game_Scene::m_ui[i]->SetEnabled(value);
		}
	}

	static void AddUI(UI* _pUI)
	{
		Game_Scene::m_ui.push_back(_pUI);
	}
	// ���ӿ� �ʿ��� ��� ���⸦ �����صΰ� �������� ����
	//Weapon* GetWeapon(wstring _name) { return m_mWeapon[_name]; }
private:
	static vector<UI*> m_ui;
public:
	static Player* pPlayer;
public:
	static int gunCnt;
	static int knifeCnt;
	static int bombCnt;
	// ��״� ������Ʈ�� �ƴ϶� ��¥ ������
	/*map<wstring, Weapon*> m_mWeapon;*/
	//vector<Weapon*> m_vecWeapon;
};

