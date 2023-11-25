#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
Button::Button()
	:texture(nullptr)
	, pos(Vec2(0.f, 0.f))
	, scale(Vec2(0.f, 0.f))
{
}

Button::Button(Vec2 _pos, Vec2 _scale)
	:pos(_pos)
	, scale(_scale)
{
}

Button::~Button()
{

}

void Button::Init()
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
	//버튼을 그려줌
}

void Button::OnClickEnter() //클릭했을때
{
	onReister();
}
void Button::OnClickStay() //꾹 눌렀을때
{

}

void Button::OnClickExit() // 땠을때
{
}
