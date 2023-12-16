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
#include "SceneMgr.h"

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
	StageMgr::GetInst()->NextStage(2 * (StageMgr::GetInst()->GetCurStage() + 1), 2, 0.1f, OnPanel);
	Game_Scene::SetActive_Panel(false);
}

void OnGun() {
	auto players = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::PLAYER);
	auto pPlayer = (Player*)players[0]; //�÷��̾�� �ϳ��ϱ� 0��°�� ������
	if (Game_Scene::gunCnt == 0) {
		//��� ���� �ڵ�
 		pPlayer->SetWeapon(0, SceneMgr::GetInst()->GetCurScene()->GetWeapon(L"Gun"));
	}
	pPlayer->SetCurWeaponIdx(0);
	Game_Scene::gunCnt++;


	OffPanel();
}
void OnKnife() {
	auto players = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::PLAYER);
	auto pPlayer = (Player*)players[0]; //�÷��̾�� �ϳ��ϱ� 0��°�� ������
	if (Game_Scene::knifeCnt == 0) {
		//��� ���� �ڵ�
		pPlayer->SetWeapon(1, SceneMgr::GetInst()->GetCurScene()->GetWeapon(L"Knife"));
	}
	pPlayer->SetCurWeaponIdx(1);
	Game_Scene::knifeCnt++;


	OffPanel();
}
void OnBomb() {
	auto players = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::PLAYER);
	auto pPlayer = (Player*)players[0]; //�÷��̾�� �ϳ��ϱ� 0��°�� ������
	if (Game_Scene::bombCnt == 0) {
		//��� ���� �ڵ�
		pPlayer->SetWeapon(2, SceneMgr::GetInst()->GetCurScene()->GetWeapon(L"Bomb"));
	}
	pPlayer->SetCurWeaponIdx(2);
	Game_Scene::bombCnt++;


	OffPanel();
}

void Game_Scene::Init()
{
	StageMgr::GetInst()->Setting();

	Game_Scene::gunCnt = 0;
	Game_Scene::knifeCnt = 0;
	Game_Scene::bombCnt = 0;

	// �÷��̾� ���� �� �ʱ�ȭ
	Player* pPlayer = new Player;
	pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayer, OBJECT_GROUP::PLAYER);

	Camera::GetInst()->SetTarget(pPlayer);


	// ���� ���� �� �ʱ�ȭ

	


	OnPanel();
	//StageMgr::GetInst()->NextStage(3, 3, 0.1f, OnPanel);

	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Select_Panel", L"Texture\\Select_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);
	Game_Scene::AddUI(bg);

	Button* gunBtn = new Button(Vec2(300, 400),
		Vec2(350, 500));
	gunBtn->SetName(L"gun");
	gunBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"GunBtn_on", L"Texture\\GunBtn_hover.bmp"));
	gunBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"GunBtn_off", L"Texture\\GunBtn.bmp"));
	gunBtn->onReister = OnGun;

	AddObject(gunBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(gunBtn);

	Button* knifeBtn = new Button(Vec2((int)WINDOW_WIDTH / 2, 400),
		Vec2(350, 500));
	knifeBtn->SetName(L"knife");
	knifeBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"KnifeBtn_on", L"Texture\\KnifeBtn_hover.bmp"));
	knifeBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"KnifeBtn_off", L"Texture\\KnifeBtn.bmp"));

	knifeBtn->onReister = OnKnife;

	AddObject(knifeBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(knifeBtn);

	Button* bombBtn = new Button(Vec2((int)WINDOW_WIDTH - 300, 400),
		Vec2(350, 500));
	bombBtn->SetName(L"bomb");
	bombBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BombBtn_on", L"Texture\\BombBtn_hover.bmp"));
	bombBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BombBtn_off", L"Texture\\BombBtn.bmp"));
	bombBtn->onReister = OnBomb;
	AddObject(bombBtn, OBJECT_GROUP::UI);
	Game_Scene::AddUI(bombBtn);

	Game_Scene::SetActive_Panel(true); //�ǳ� �����

	Weapon* pGun = new Gun;
	pGun->SetPos((Vec2({ 0, 0 })));
	pGun->SetScale(Vec2(150.f, 150.f));
	pGun->SetOwner(pPlayer);
	m_mWeapon.insert({ L"Gun", pGun });
	AddWeapon(pGun);

	Weapon* pKnife = new Knife;
	pKnife->SetPos((Vec2({ 0, 0 })));
	pKnife->SetScale(Vec2(50.f, 50.f));
	pGun->SetOwner(pPlayer);
	m_mWeapon.insert({ L"Knife", pKnife });
	AddWeapon(pKnife);

	Weapon* pBomb = new Bomb;
	pBomb->SetPos((Vec2({ 0, 0 })));
	pBomb->SetScale(Vec2(50.f, 50.f));
	pGun->SetOwner(pPlayer);
	m_mWeapon.insert({ L"Bomb", pBomb });
	pGun->SetName(L"Bomb");
	AddWeapon(pBomb);


	// �� ���� �� �ʱ�ȭ (�׽�Ʈ ����)
	{
		//StageMgr::GetInst()->NextStage(0, 0, 0.f, OnPanel);
	}
	// ���� ����
	//ResMgr::GetInst()->Play(L"BGM");


	//�⵿ ����
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::BULLET);
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

	wstring ws = L"enemy : " + to_wstring(StageMgr::GetInst()->enemyCountInWave);

	HFONT font = CreateFontW(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
	SelectObject(_dc, font);

	TextOutW(_dc, 100, 100, ws.c_str(), ws.length());

	wstring ws2 = to_wstring(StageMgr::GetInst()->GetCurStage()) + L" wave";

	TextOut(_dc, 100, 50, ws2.c_str(), ws2.length());

	DeleteObject(font);
}

void Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
