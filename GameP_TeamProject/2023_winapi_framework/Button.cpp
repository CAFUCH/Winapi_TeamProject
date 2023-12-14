#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "Game_Scene.h"

typedef void(*myFuncDef)(void);

Button::Button(Vec2 _pos, Vec2 _scale)
	:on_tex(nullptr)
	, off_tex(nullptr)
	, pos(_pos)
	, scale(_scale)
{
	SetPos(_pos);
	SetScale(_scale);

	left = pos.x - (scale.x / 2);
	right = pos.x + (scale.x / 2);
	bottom = pos.y + (scale.y / 2);
	top = pos.y - (scale.y / 2);

	cur_tex = on_tex;
}

Button::~Button()
{

}

void Button::Update()
{

	if (enabled) {
		Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();

		if (left <= mousePos.x
			&& right >= mousePos.x
			&& top <= mousePos.y
			&& bottom >= mousePos.y)  //��ư �ȿ� �ֳ� Ȯ��
		{
			cur_tex = on_tex;

			KEY_STATE state = KeyMgr::GetInst()->GetKey(KEY_TYPE::LBUTTON);
			if (state == KEY_STATE::DOWN) {
				OnClickEnter();
			}
			else if (state == KEY_STATE::PRESS) {
				OnClickStay();
			}
			else if (state == KEY_STATE::UP) {
				OnClickExit();
			}
		}
		else {
			cur_tex = off_tex;
		}
	}


}
void Button::Render(HDC _dc)
{
	//��ư�� �׷���

	if (enabled == true) {

		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();

		if (nullptr != cur_tex) {
			int Width = cur_tex->GetWidth();
			int Height = cur_tex->GetHeight();
			////ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
			TransparentBlt(_dc
				, (int)(vPos.x - vScale.x / 2)
				, (int)(vPos.y - vScale.y / 2)
				, Width, Height, cur_tex->GetDC()
				, 0, 0, Width, Height, RGB(255, 0, 255));
		}

		
		if (name == L"gun") {
			wstring ws = L"Level " + to_wstring(Game_Scene::gunCnt);

			TextOut(_dc, 235, 550, ws.c_str(), ws.length());
		}
		if (name == L"knife") {
			wstring ws = L"Level " + to_wstring(Game_Scene::knifeCnt);

			TextOut(_dc, 570, 550, ws.c_str(), ws.length());
		}
		if (name == L"bomb") {
			wstring ws = L"Level " + to_wstring(Game_Scene::bombCnt);

			TextOut(_dc, 915, 550, ws.c_str(), ws.length());
		}

		
	}
}


void Button::OnClickEnter() //Ŭ��������
{
	((myFuncDef)onReister)(); //void �����ʹ� �̷��� ����
}
void Button::OnClickStay() //�� ��������
{

}

void Button::OnClickExit() // ������
{
}
