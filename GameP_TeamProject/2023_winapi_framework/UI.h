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
	void SetEnabled(bool value) {
		enabled = value;
	}
protected:
	bool enabled;
};

