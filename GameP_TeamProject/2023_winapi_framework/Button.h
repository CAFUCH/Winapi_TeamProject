#pragma once
#include "UI.h"
class Texture;
class Button :
	public UI
{
public:
	Button();
	~Button();
	Button(Vec2 _pos, Vec2 _scale);
public:
	void Init() override;
	void Update() override;
	void Render(HDC _dc) override;
public:
	void OnClickEnter();
	void OnClickStay();
	void OnClickExit();
public:
	void SetPos(Vec2 _vPos) { pos = _vPos; }
	const Vec2& GetPos() const { return pos; }

	const Vec2& GetScale() const { return scale; }
	void SetScale(Vec2 _vScale) { scale = _vScale; }
public:
	void (*onReister)();
private:
	bool checkClick; //마우스가 눌린상태인지
	Vec2 pos;
	Vec2 scale;
	Vec2 mousePos;

	Texture* texture;
	BUTTON_STATE* _curState;
};

