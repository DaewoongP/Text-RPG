#include "stdafx.h"
#include "Obj.h"

void CObj::SET_Damage(int _iAttack)
{
	m_Object.m_iHp -= _iAttack;
}

CObj::CObj()
{
	// ����ü�� 0���� �ʱ�ȭ.
	memset(&m_Object, 0, sizeof(INFO));
}


CObj::~CObj()
{
}
