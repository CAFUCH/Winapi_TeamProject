#pragma once
#include "Object.h"
#include "Player.h"
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
protected:
	Player* _player;
};

