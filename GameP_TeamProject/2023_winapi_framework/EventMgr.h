#pragma once
class Object;
class Weapon;
struct tEvent
{
	EVENT_TYPE eEve; // 이벤트 타입
	Object* Obj;
	Weapon* Wea;
	OBJECT_GROUP ObjType;
};
class EventMgr
{
	SINGLE(EventMgr);
public:
	void Update();
	void DeleteObject(Object* _pObj);
	void DeleteWeapon(Weapon* _pWea);
private:
	void Excute(const tEvent& _eve);
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecObjDead;
	vector<Weapon*> m_vecWeaDead;
};

