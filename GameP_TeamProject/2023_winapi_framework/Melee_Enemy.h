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
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void StayCollision(Collider* _pOther)  override;
	virtual void ExitCollision(Collider* _pOther)  override;

public:
	void Update() override;
	//void Render(HDC _dc) override;
public:
	const Player GetPlayer() const { _player; }
	void SetPlayer(Player _p) { _player = _p; }
private:
	// sprite
	Texture* m_pTex;
	Vec2 _playerPos;
	Player _player;
};

