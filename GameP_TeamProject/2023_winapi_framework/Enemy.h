#pragma once
#include "Object.h"
#include "Player.h"
class Enemy :
	public Object
{
public:
	Enemy();
	~Enemy();
public:
	const Player GetPlayer() const { _player; }
	void SetPlayer(Player _p) { _player = _p; }
public:
	void SetTexure(Texture* _tex) { m_pTex = _tex; };
protected:
	Texture* m_pTex;
	Player _player;
};

