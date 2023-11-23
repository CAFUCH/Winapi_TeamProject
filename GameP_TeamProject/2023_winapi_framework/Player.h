#pragma once
#include "Object.h"
#include <wtypes.h> // pch���� ���ְ� ���� �ʳ�??
class Texture; class Weapon;
class Player :
    public Object
{
public:
    Player();
    ~Player();

public:
    void Update() override;
    void Render(HDC _dc) override;

private:
    // �÷��̾� �̹���
    Texture* m_pTex;
    // �÷��̾� ����
    Stat m_stat;
    // �÷��̾� ���� ����
    Weapon* m_curWeapon;
    // �÷��̾� ���� ����
    vector<Weapon*> m_vecWeapon[3];
};

