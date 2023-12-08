#pragma once
#include "Obj.h"

class CMyMap
{
public:
	virtual void	Initialize() = 0;
	virtual void	Update() = 0;
	virtual void	Release() = 0;

	void	SET_Player(CObj* _Player) { m_pPlayer = _Player; }

public:
	CMyMap();
	virtual ~CMyMap();
protected:
	CObj*	 m_pPlayer;
};

