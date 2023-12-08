#pragma once
#include "Define.h"
#include "Obj.h"


class CMonster : public CObj
{

public:
	void	Initialize();
	void	Update();
	void	Release();

	CMonster(int _iInput);
	~CMonster();

public:
	virtual	void	Render(void); 
	virtual void	Create_Object(char* _pName, int _iMaxHp, int _iAttack,
		int _iGold, int _iLevel, int _iMaxExp, int _iExp);
	void	Select_Job(void) {}

};

