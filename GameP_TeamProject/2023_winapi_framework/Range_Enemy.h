#pragma once
#include "Enemy.h"
#include "Object.h"
#include "Player.h"
class Texture;
class Range_Enemy :
    public Enemy
{
public:
	Range_Enemy(int _idx, ENTITY_ELEMENT_TYPE _type, int _hp, float _damage, float _atkDelay);
	~Range_Enemy();
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
	float curTime;
	float atkDelay;
	Texture* m_pTex;
	Vec2 _playerPos;
	ENTITY_ELEMENT_TYPE type;
};

