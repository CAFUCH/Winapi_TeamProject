#pragma once
#include "Enemy.h"
#include "Object.h"
#include "Player.h"
class Texture;
class Melee_Enemy :
	public Enemy
{
public:
	Melee_Enemy(int _idx);
	~Melee_Enemy();
public:
	//void SetOffTexture(Texture* _tex) { cur_tex = _tex; }
public:
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void StayCollision(Collider* _pOther)  override;
	virtual void ExitCollision(Collider* _pOther)  override;

public:
	void Update() override;

private:
	// sprite
	//Texture* cur_tex;
	// sprite
	Texture* m_pTex;
	Vec2 _playerPos;
	
};

