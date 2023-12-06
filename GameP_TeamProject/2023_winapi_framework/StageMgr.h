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
	void NextStage(int enemyCount, float spawnDelay);
public:
	const int GetCurStage() const
	{
		return curStage;
	}

private:
	void EnemySpawn();
private:
	float curTime;
	float spawnDelay;
	int curStage;
	int enemycount;
	bool isStageStart;
	bool allDead;
};

