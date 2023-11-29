#pragma once
#include "Object.h"
class UI :
	public Object
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC _dc);
	void SetEnabled(bool _value) { enabled = _value; }
	bool GetEnabled() { return enabled; }
protected:
	bool enabled;
};

