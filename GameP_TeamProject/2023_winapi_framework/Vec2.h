#pragma once
#include<assert.h>
class Vec2
{
public:
	Vec2();
	~Vec2();
	Vec2(float _x, float _y);
	Vec2(int _x, int _y);
	Vec2(POINT _pt);
	Vec2(const Vec2& _vec);
public:
	float Length() { return (float)(sqrt(pow(x, 2) + pow(y, 2))); }
	double Distance(Vec2 _v1, Vec2 _v2)
	{
		return sqrt(pow(_v2.x - _v1.x, 2) + pow(_v2.y - _v1.y, 2));
	}
	Vec2& Normalize()
	{
		float fLen = Length();
		// 0�̸� �ȵ�.
		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}
	Vec2 operator + (Vec2 _vOther)
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}
	Vec2 operator - (Vec2 _vOther)
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}
	Vec2 operator * (Vec2 _vOther)
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}
	Vec2 operator / (Vec2 _vOther)
	{
		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return Vec2(x / _vOther.x, y / _vOther.y);
	}
	Vec2 operator * (int _i)
	{
		return Vec2(x * (float)_i, y * (float)_i);
	}
public:
	float x;
	float y;
};

