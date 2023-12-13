#pragma once
#include "UI.h"
class Texture;
class Panel :
	public UI
{
public:
	Panel();
	~Panel();

private:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC _dc);
public:
	void SetTexture(Texture* _tex);
private:
	Texture* tex;
};

