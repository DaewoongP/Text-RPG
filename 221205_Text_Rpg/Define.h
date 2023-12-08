#pragma once
#define SAFE_DELETE(p)			if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p)	if(p) {delete []p; p= nullptr;}

template<typename T>
void Safe_Delete(T _ptr)
{
	if (_ptr)
	{
		delete _ptr;
		_ptr = nullptr;
	}
}



#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif


typedef struct tagINFO
{
	char	m_szName[16];
	int		m_iLevel;
	int		m_iHp;
	int		m_iMaxHp;
	int		m_iAttack;
	int		m_iExp;
	int		m_iMaxExp;
	int		m_iGold;
	bool	isPlayer;

}INFO;

typedef struct tagEquipINFO
{
	char	m_szName[16];
	int		m_iRank; // µî±Þ?
	int		m_iReqLv;
	int		m_iAttack;
	int		m_iHp;
	int		m_iPrice;
	int		m_iCount;
	bool	m_isEquiped;
}EQINFO;


enum MyEnum
{
	NEWGAME = 1,
	LOADGAME,
	QUIT,
};

enum MyJob
{
	WARRIOR = 1,
	MAGE,
	ROGUE,
};

enum MyGame
{
	FIELD = 1,
	STORE,
	RETURN,
};