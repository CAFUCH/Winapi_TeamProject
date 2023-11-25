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
		&& bottom >= mousePos.y)  //��ư �ȿ� �ֳ� Ȯ��
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
	//��ư�� �׷���
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
