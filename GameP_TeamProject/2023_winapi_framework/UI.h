#pragma once
class UI
{
public:
	UI();
	virtual ~UI();
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC _dc);
protected:
	bool enabled;
};

