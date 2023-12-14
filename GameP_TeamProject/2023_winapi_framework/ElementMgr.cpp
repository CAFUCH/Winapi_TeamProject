#include "pch.h"
#include "ElementMgr.h"

const float ElementMgr::Elemenet(ENTITY_ELEMENT_TYPE _this, ENTITY_ELEMENT_TYPE _other, float _damage)
{
	if ((int)_this + 1 == (int)ENTITY_ELEMENT_TYPE::END)
	{
		if (_other == ENTITY_ELEMENT_TYPE::WATER)
			return _damage * 1.5f;
	}
	else
	{
		if ((int)_this < (int)_other)
			return _damage * 1.5f;
		else
			return _damage;
	}
}
