#pragma once
#include "Object.h"

class Texture; class Scene;
class Weapon :
    public Object
{
public:
    Weapon();
    ~Weapon();

public:
    void Update();

public:
    // 공격 함수 (플레이어 호출)
    virtual void Attack(Vec2 dir) abstract;

protected:
    // 원소
    ENTITY_ELEMENT_TYPE m_eElementType;

protected:
    // sprite
    Texture* m_pTex;
    // 현재 씬
    std::shared_ptr<Scene> m_pCurScene;
    // 현재 씬의 적
    vector<Object*> m_vecEnemy;
};

