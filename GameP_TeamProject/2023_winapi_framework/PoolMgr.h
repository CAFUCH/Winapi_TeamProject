#pragma once
class Object;
class PoolMgr
{
	SINGLE(PoolMgr);
	// 풀 매니저... 뭐 필요하더라

public:
	void Init();
	void Update();

public:
	// 어렵다 어려워!
	Object* CreateObject() { return pool.front(); }
	void DeleteObject(Object* _obj) { pool.push(_obj); }

	// 그냥 Obj를 넘겨주면서 초기화 할 수 있는지?
	// 받은 Obj의 기본 정보를 지워야 한다거나?

private:
	queue<Object*> pool;
};

