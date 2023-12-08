#pragma once
#include "Define.h"
class CItem
{
public:
	void SET_Count(int _iCount) { m_EQObject.m_iCount += _iCount; }

	EQINFO GET_Info(void) { return m_EQObject; }

	void Render();

public:
	CItem();
	virtual ~CItem();

protected:
	EQINFO			m_EQObject;

	static int		m_iAllCount;
};

