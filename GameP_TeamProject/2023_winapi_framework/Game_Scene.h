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
	// 게임에 필요한 모든 무기를 생성해두고 가져오기 위해
	//Weapon* GetWeapon(wstring _name) { return m_mWeapon[_name]; }
private:
	static vector<UI*> m_ui;
public:
	static Player* pPlayer;
public:
	static int gunCnt;
	static int knifeCnt;
	static int bombCnt;
	// 얘네는 컴포넌트가 아니라 진짜 무기임
	/*map<wstring, Weapon*> m_mWeapon;*/
	//vector<Weapon*> m_vecWeapon;
};

