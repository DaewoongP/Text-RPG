#include "stdafx.h"
#include "Obj.h"

void CObj::SET_Damage(int _iAttack)
{
	m_Object.m_iHp -= _iAttack;
}

CObj::CObj()
{
	// 구조체를 0으로 초기화.
	memset(&m_Object, 0, sizeof(INFO));
}


CObj::~CObj()
{
}
