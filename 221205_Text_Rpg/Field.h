#pragma once
#include "MyMap.h"
#include "Player.h"
#include "Monster.h"
class CField : public CMyMap
{
public:
	void	Initialize();
	void	Update();
	void	Release();

	void	Battle();
public:
	CField();
	~CField();

private:
	CObj*	m_pMonster;
};

