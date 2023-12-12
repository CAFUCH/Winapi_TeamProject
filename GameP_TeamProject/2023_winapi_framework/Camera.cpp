#include "pch.h"
#include "Camera.h"
#include "Object.h"
#include "Core.h"
#include "TimeMgr.h"

void Camera::Update()
{
    if (m_pTarget)
    {
        if (m_pTarget->GetIsDead())
        {
            m_pTarget = nullptr;
        }
        else
        {
            m_vLookAt = m_pTarget->GetPos();
        }
    }

    CalDiff();
}
void Camera::CalDiff()
{
    //// 이전 LookAt과 현재 LookAt의 차이값을 보정해서 현재 LookaT을 구한다.
    //m_vLootAt; // 지금 보고 있는 위치
    //m_vPrevLookAt; // 이전 위치
    //// 이걸 보정해야한다.. 이걸 일정 시간에 따라서 쫓아가게 해보자.

    // 시간에 따라 이동
    m_fAccTime += fDT;
    if (m_fAccTime >= m_fTime)
    {
        m_vCurLookAt = m_vLookAt; // 시간되면 이렇게 현재Look을 세팅
    }
    else
    {
        Vec2 vLookDir = m_vLookAt - m_vPrevLookAt; // 쫓아갈 방향 벡터
        m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * m_fSpeed * fDT;

    }
    //// 그냥 쫓아가게
    //Vec2 vLookDir = m_vLootAt - m_vPrevLookAt; // 쫓아갈 방향 벡터
    //m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * 500.f * fDT;

    Vec2 vResolution = Core::GetInst()->GetResolution();
    Vec2 vCenterPos = { vResolution.x / 2, vResolution.y / 2 };

    // 보고 있는 위치와 중심위치와 차이 값.
    //m_vDiff = m_vLootAt - vCenterPos;
    m_vDiff = m_vCurLookAt - vCenterPos;
    //m_vPrevLookAt = m_vLootAt;
    m_vPrevLookAt = m_vCurLookAt;
}
