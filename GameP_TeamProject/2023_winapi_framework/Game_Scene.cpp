#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"
#include "Camera.h"

#include "ResMgr.h"

#include "Player.h"

#include "Gun.h"
#include "Knife.h"
#include "Bomb.h"

#include "Object.h"

#include "KeyMgr.h"
#include "ResMgr.h"
#include "CollisionMgr.h"

#include "Melee_Enemy.h"
#include "Chase_State_Melee.h"
#include "Idle_State.h"

#include "StageMgr.h"

#include "Panel.h"
#include "Button.h"

vector<UI*> Game_Scene::m_ui;
int Game_Scene::gunCnt = 0;
int Game_Scene::knifeCnt = 0;
int Game_Scene::bombCnt = 0;

void OnPanel() {
	Game_Scene::SetActive_Panel(true);
}
void OffPanel() {
	StageMgr::GetInst()->NextStage(3, 3, 0.1f, OnPanel);
	Game_Scene::SetActive_Panel(false);
}

void OnGun() {
	if (Game_Scene::gunCnt == 0) {
		//얻는 무기 코드
	}

	Game_Scene::bombCnt++;
	OffPanel();
}
void OnKnife() {
	if (Game_Scene::knifeCnt == 0) {
		//얻는 무기 코드
	}
	OffPanel();
}
void OnBomb() {
	if (Game_Scene::bombCnt == 0) {
		//얻는 무기 코드
	}
	OffPanel();
}

void Game_Scene::Init()
{
	// 플레이어 생성 및 초기화
	{
		Object* pPlayer = new Player;
		pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
		pPlayer->SetScale(Vec2(100.f, 100.f));
		AddObject(pPlayer, OBJECT_GROUP::PLAYER);

		Camera::GetInst()->SetTarget(pPlayer);
	}

	// 무기 생성 및 초기화
	{
		Weapon* pGun = new Gun;
		pGun->SetPos((Vec2({ 0, 0 })));
		pGun->SetScale(Vec2(150.f, 150.f));
		m_mWeapon.insert({ L"Gun", pGun });

		Weapon* pKnife = new Knife;
		pKnife->SetPos((Vec2({ 0, 0 })));
		pKnife->SetScale(Vec2(50.f, 50.f));
		m_mWeapon.insert({ L"Knife", pKnife });

		Weapon* pBomb = new Bomb;
		pBomb->SetPos((Vec2({ 0, 0 })));
		pBomb->SetScale(Vec2(50.f, 50.f));
		m_mWeapon.insert({ L"Bomb", pBomb });
	}

	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Select_Panel", L"Texture\\Select_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);
	Game_Scene::AddUI(bg);

	Button* gunBtn = new Button(Vec2(300, 400),
		Vec2(350, 500));
	gunBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"GunBtn_on", L"Texture\\GunBtn_hover.bmp"));
	gunBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"GunBtn_off", L"Texture\\GunBtn.bmp"));
	gunBtn->onReister = OnGun;

	AddObject(gunBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(gunBtn);

	Button* knifeBtn = new Button(Vec2((int)WINDOW_WIDTH / 2, 400),
		Vec2(350, 500));
	knifeBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"KnifeBtn_on", L"Texture\\KnifeBtn_hover.bmp"));
	knifeBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"KnifeBtn_off", L"Texture\\KnifeBtn.bmp"));
	knifeBtn->onReister = OnKnife;

	AddObject(knifeBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(knifeBtn);

	Button* bombBtn = new Button(Vec2((int)WINDOW_WIDTH - 300, 400),
		Vec2(350, 500));
	bombBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BombBtn_on", L"Texture\\BombBtn_hover.bmp"));
	bombBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BombBtn_off", L"Texture\\BombBtn.bmp"));
	bombBtn->onReister = OnBomb;
	AddObject(bombBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(bombBtn);

	Game_Scene::SetActive_Panel(false); //판넬 지우기


	// 적 생성 및 초기화 (테스트 버전)
	{
		StageMgr::GetInst()->NextStage(1, 1, 0.f, OnPanel);
	}
	// 사운드 세팅
	//ResMgr::GetInst()->Play(L"BGM");


	//출동 세팅
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::WEAPON, OBJECT_GROUP::MONSTER);
}
void Game_Scene::Update()
{
	Scene::Update();
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);

	SetBkMode(_dc, 0);

	wstring ws = to_wstring(StageMgr::GetInst()->enemyCountInWave);
	TextOut(Core::GetInst()->GetMainDC(), 100, 100, ws.c_str(), ws.length());

}

void Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
