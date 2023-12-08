#pragma once
#include "Define.h"
class CObj
{
public:
	virtual void	Initialize() = 0;
	virtual void	Update() = 0;
	virtual void	Release() = 0;

	void	SET_Damage(int _iAttack);

	virtual void	Render(void) = 0;

	virtual void	Create_Object(char* _pName, int _iMaxHp, int _iAttack,
		int _iGold, int _iLevel, int _iMaxExp, int _iExp) = 0;

	INFO	GET_INFO(void) { return m_Object; }

public:
	CObj& operator -=(CObj& rObj)
	{
		this->SET_Damage(rObj.GET_INFO().m_iAttack);
		//rObj.SET_Damage(this->GET_INFO().m_iAttack);
		return *this;
	}

public:
	CObj();
	virtual ~CObj();

protected:
	INFO	m_Object;
};

