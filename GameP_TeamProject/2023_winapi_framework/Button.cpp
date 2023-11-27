#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"
Button::Button()
	:on_tex(nullptr)
	, off_tex(nullptr)
	, pos(Vec2(0.f, 0.f))
	, scale(Vec2(0.f, 0.f))
{
	on_tex = ResMgr::GetInst()->TexLoad(L"gameStart_btn_on", L"Texture\\GameStart_btn_on.bmp");
	off_tex = ResMgr::GetInst()->TexLoad(L"gameStart_btn_off", L"Texture\\GameStart_btn_off.bmp");

	cur_tex = off_tex;
}

Button::Button(Vec2 _pos, Vec2 _scale)
	:pos(_pos)
	, scale(_scale)
{
}

Button::~Button()
{

}

void Button::Update()
{
	Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();

	cur_tex = off_tex;

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

}
void Button::Render(HDC _dc)
{
	//��ư�� �׷���
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = cur_tex->GetWidth();
	int Height = cur_tex->GetHeight();
	////ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, cur_tex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
}

void Button::OnClickEnter() //Ŭ��������
{
	onReister();
}
void Button::OnClickStay() //�� ��������
{

}

void Button::OnClickExit() // ������
{
}
