#pragma once
class Object;
class PoolMgr
{
	SINGLE(PoolMgr);
	// Ǯ �Ŵ���... �� �ʿ��ϴ���

public:
	void Init();
	void Update();

public:
	// ��ƴ� �����!
	Object* CreateObject() { return pool.front(); }
	void DeleteObject(Object* _obj) { pool.push(_obj); }

	// �׳� Obj�� �Ѱ��ָ鼭 �ʱ�ȭ �� �� �ִ���?
	// ���� Obj�� �⺻ ������ ������ �Ѵٰų�?

private:
	queue<Object*> pool;
};

