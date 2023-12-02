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
	const Player* GetPlayer() const { _player; }
	void SetAI(AI* ai) { _ai = ai; }
protected:
	Player* _player;
	AI* _ai;
};

