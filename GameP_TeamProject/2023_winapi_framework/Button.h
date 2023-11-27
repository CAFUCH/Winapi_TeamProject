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
	void Update() override;
	void Render(HDC _dc) override;
protected:
	void OnClickEnter();
	void OnClickStay();
	void OnClickExit();
public: //혹시 필요할 수도 잇으니깐
	void SetPos(Vec2 _vPos) { pos = _vPos; }
	const Vec2& GetPos() const { return pos; }

	const Vec2& GetScale() const { return scale; }
	void SetScale(Vec2 _vScale) { scale = _vScale; }
public:
	void (*onReister)();
private:
	bool checkClick; //마우스가 눌린상태인지

	float left = pos.x - scale.x;
	float right = pos.x + scale.x;
	float bottom = pos.y + scale.y;
	float top = pos.y - scale.y;

	Vec2 pos;
	Vec2 scale;
	Vec2 mousePos;
	Texture* off_tex;
	Texture* on_tex;
	Texture* cur_tex;
	BUTTON_STATE* _curState;
};

