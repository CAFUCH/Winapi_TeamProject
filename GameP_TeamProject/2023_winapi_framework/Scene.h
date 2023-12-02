#pragma once
//#include "Object.h"
class Object;
class Weapon;
class Scene
{
public:
	Scene();
	virtual ~Scene();	
	// Init(), Update(), Render(), Release();
	virtual void Init() abstract;
	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();
public:
	const vector<Object*>& GetGroupObject(OBJECT_GROUP _etype) const
	{
		return m_vecObj[(UINT)_etype];
	}
	Weapon* GetWeapon(wstring _name) { return m_mWeapon[_name]; }
public:
	void AddObject(Object* _pObj, OBJECT_GROUP _eType)
	{
		m_vecObj[(UINT)_eType].push_back(_pObj);
	}
protected:
//	Object*  m_obj;
	vector<Object*> m_vecObj[(UINT)OBJECT_GROUP::END];
	map<wstring, Weapon*> m_mWeapon;
};

