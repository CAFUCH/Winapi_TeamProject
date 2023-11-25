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
	void SetEnabled(bool value) {
		enabled = value;
	}
protected:
	bool enabled;
};

