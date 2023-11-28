#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"
Button::Button(Vec2 _pos, Vec2 _scale)
	:on_tex(nullptr)
	, off_tex(nullptr)
	, pos(_pos)
	, scale(_scale)
{
	SetPos(_pos);
	SetScale(_scale);

	on_tex = ResMgr::GetInst()->TexLoad(L"gameStart_btn_on", L"Texture\\GameStart_btn_on.bmp");
	off_tex = ResMgr::GetInst()->TexLoad(L"gameStart_btn_off", L"Texture\\GameStart_btn_off.bmp");

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
	Vec2 mousePos = KeyMgr::GetInst()->GetMousePos();

	if (left <= mousePos.x
		&& right >= mousePos.x
		&& top <= mousePos.y
		&& bottom >= mousePos.y)  //버튼 안에 있나 확인
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
void Button::Render(HDC _dc)
{
	//버튼을 그려줌
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

void Button::OnClickEnter() //클릭했을때
{
	//onReister();
}
void Button::OnClickStay() //꾹 눌렀을때
{

}

void Button::OnClickExit() // 땠을때
{
}
