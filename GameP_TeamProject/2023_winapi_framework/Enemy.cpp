#include "pch.h"
#include "Enemy.h"
#include "SceneMgr.h"
#include "Scene.h"
Enemy::Enemy()
{
	auto players = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::PLAYER);
	//if (nullptr != players)
	_player = (Player*)players[0]; //플래이어는 하나니깐 0번째를 가져옴
}

Enemy::~Enemy()
{

}
