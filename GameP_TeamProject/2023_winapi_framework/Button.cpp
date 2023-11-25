#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
Button::Button()
	:texture(nullptr)
	,pos(Vec2(0.f, 0.f))
	,scale(Vec2(0.f, 0.f))
{
}

Button::Button(Vec2 _pos, Vec2 _scale)
	:pos(_pos)
	,scale(_scale)
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

}
void Button::Render(HDC _dc)
{

}

void Button::OnClickEnter()
{
	onReister();
}

void Button::OnClickStay()
{
}

void Button::OnClickExit()
{
}
