#include "pch.h"
#include "Enemy.h"
#include "SceneMgr.h"
#include "Scene.h"
Enemy::Enemy()
{
	auto players = SceneMgr::GetInst()->GetCurScene()->GetGroupObject(OBJECT_GROUP::PLAYER);
	if (nullptr != _player)
		_player = (Player*)players[0]; //�÷��̾�� �ϳ��ϱ� 0��°�� ������
}

Enemy::~Enemy()
{

}
