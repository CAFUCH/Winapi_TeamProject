#pragma once
class Object;
class Texture;
class Animation;
class Animator
{
public:
	Animator();
	~Animator();

public:
	void Update();
	void Render(HDC _dc);

public:
	// 애니메이션 생성함수
	void CreateAnim(const wstring& _strName, Texture* _pTex,
					Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep,
					UINT _framecount, float _fDuration);

	// 애니메이션 찾기함수
	Animation* FindAnim(const wstring& _strName);

	// 애니메이션 플레이 함수
	void PlayAnim(const wstring& _strName, bool _bRepeat, int _repeatcnt = 1);

public:
	Object* GetObj() const { return m_pOwner; }
	const bool& GetRepeat() const { return m_IsRepeat; }
	const int& GetRepeatcnt() const { return m_repeatcnt; }
	void SetRepeatcnt() { --m_repeatcnt; }

private:
	// 현재 객체
	Object* m_pOwner;
	// 객체 가지고 있는 animation들
	map<wstring, Animation*> m_mapAnim;
	// 현재 animation
	Animation* m_pCurAnim;

	friend class Object;

	// 반복
	bool	m_IsRepeat;
	// 반복 횟수
	int		m_repeatcnt;
};

