#pragma once
class Enemy;
class Object;
class StageMgr
{
	SINGLE(StageMgr);
public:
	void Init();
	void Update();
	void Setting();
public:
	void NextStage(int _enemyCount, int _spawnCount, float spawnDelay, void* (_action));
	//(���)�� (���) (����)���� ����, ���� �� ������ ������ (�Լ�)
public:
	const int GetCurStage() const
	{
		return curStage;
	}
public:
	void Dead() { isUpdate = false; }
private:
	void EnemySpawn(int _eCount);

public:
	int enemyCountInWave;
	bool isUpdate;
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

