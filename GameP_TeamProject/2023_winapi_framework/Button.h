#pragma once
#include "UI.h"
class Texture;
class Button :
	public UI
{
public:
	Button(Vec2 _pos, Vec2 _scale);
	~Button();
public:
	void Update() override;
	void Render(HDC _dc) override;
protected:
	void OnClickEnter();
	void OnClickStay();
	void OnClickExit();
public: //Ȥ�� �ʿ��� ���� �����ϱ�
	/*void SetPos(Vec2 _vPos) { pos = _vPos; }
	const Vec2& GetPos() const { return pos; }

	const Vec2& GetScale() const { return scale; }
	void SetScale(Vec2 _vScale) { scale = _vScale; }*/
public:
public:
	void* onReister;
private:
	bool checkClick; //���콺�� ������������

	float left;
	float right;
	float bottom;
	float top;

	Vec2 pos;
	Vec2 scale;
	Vec2 mousePos;
	Texture* off_tex;
	Texture* on_tex;
	Texture* cur_tex;
};

