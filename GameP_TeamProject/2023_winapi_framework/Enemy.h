#pragma once
#include "Object.h"
#include "Player.h"
#include "AI.h"
class Texture;
class Enemy :
	public Object
{
public:
	Enemy();
	~Enemy();
public:
	//void Render(HDC _hdc) override;
public:
	const Player* GetPlayer() const { return _player; }
	void SetAI(AI* ai) { _ai = ai; }
public:
	wstring ANIM_RIGHT_HASH;
	wstring ANIM_LEFT_HASH;
	wstring ANIM_RIGHT_HIT_HASH;
	wstring ANIM_LEFT_HIT_HASH;
protected:
	Player* _player;
	AI* _ai;
};

