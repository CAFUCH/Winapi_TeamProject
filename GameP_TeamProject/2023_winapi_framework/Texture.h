#pragma once
#include "Res.h"
class Texture :
    public Res
{
private:
    Texture();
    ~Texture();
    friend class ResMgr;
public:
    void Load(const wstring& _strFilePath);
    LONG& GetWidth() { return (m_bitInfo.bmWidth); }
    LONG& GetHeight() { return (m_bitInfo.bmHeight); }
    HDC& GetDC() { return m_hDC; }
private:
    HBITMAP m_hBit;
    HDC     m_hDC;
    BITMAP  m_bitInfo;
};

