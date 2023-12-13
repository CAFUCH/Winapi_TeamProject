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
	//(몇마리)를 (몇번) (몇초)마다 실행, 적이 다 죽으면 실행함 (함수)
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

