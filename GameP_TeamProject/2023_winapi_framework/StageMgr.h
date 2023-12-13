#pragma once
class Enemy;
class Object;
class StageMgr
{
	SINGLE(StageMgr);
public:
	void Init();
	void Update();
public:
	void NextStage(int _enemyCount, int _spawnCount, float spawnDelay, void* (_action));
	//(���)�� (���) (����)���� ����, ���� �� ������ ������ (�Լ�)
public:
	const int GetCurStage() const
	{
		return curStage;
	}
private:
	void EnemySpawn(int _eCount);

public:
	int enemyCountInWave;
private:
	float curTime;
	float spawnDelay;

	int curStage;
	int spawnCount;
	int enemyCount;
	bool isStageStart;
	bool allDead;


	void* action;
};

