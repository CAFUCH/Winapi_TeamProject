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
	void NextStage();
	void EnemySpawn(float delay);
public:
	const int GetCurStage() const
	{
		return curStage;
	}
private:
	float curTime;
	int curStage;
	map<int, vector<Enemy*>> vec_Obj;

};

