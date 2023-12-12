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
    //// ���� LookAt�� ���� LookAt�� ���̰��� �����ؼ� ���� LookaT�� ���Ѵ�.
    //m_vLootAt; // ���� ���� �ִ� ��ġ
    //m_vPrevLookAt; // ���� ��ġ
    //// �̰� �����ؾ��Ѵ�.. �̰� ���� �ð��� ���� �Ѿư��� �غ���.

    // �ð��� ���� �̵�
    m_fAccTime += fDT;
    if (m_fAccTime >= m_fTime)
    {
        m_vCurLookAt = m_vLookAt; // �ð��Ǹ� �̷��� ����Look�� ����
    }
    else
    {
        Vec2 vLookDir = m_vLookAt - m_vPrevLookAt; // �Ѿư� ���� ����
        m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * m_fSpeed * fDT;

    }
    //// �׳� �Ѿư���
    //Vec2 vLookDir = m_vLootAt - m_vPrevLookAt; // �Ѿư� ���� ����
    //m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * 500.f * fDT;

    Vec2 vResolution = Core::GetInst()->GetResolution();
    Vec2 vCenterPos = { vResolution.x / 2, vResolution.y / 2 };

    // ���� �ִ� ��ġ�� �߽���ġ�� ���� ��.
    //m_vDiff = m_vLootAt - vCenterPos;
    m_vDiff = m_vCurLookAt - vCenterPos;
    //m_vPrevLookAt = m_vLootAt;
    m_vPrevLookAt = m_vCurLookAt;
}
