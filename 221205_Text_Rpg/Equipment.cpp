#include "stdafx.h"
#include "Equipment.h"
void CEquipment::Initialize()
{
}
void CEquipment::Update()
{
}
void CEquipment::Release()
{
}
// 이름, 등급, 렙제, 공격력, 체력, 가격, 개수, 장착여부
void CEquipment::Create_Weapon(char* _pName, int _iRank, int _iReqLv, int _iAttack, int _iPrice, int _iCount, bool _isEquiped)
{
	strcpy_s(m_EQObject.m_szName, sizeof(m_EQObject.m_szName), _pName);
	m_EQObject.m_iRank = _iRank;
	m_EQObject.m_iReqLv = _iReqLv;
	m_EQObject.m_iAttack = _iAttack;
	m_EQObject.m_iHp = NULL;
	m_EQObject.m_iPrice = _iPrice;
	m_EQObject.m_iCount = _iCount;
	m_EQObject.m_isEquiped = _isEquiped;
} // 이거 나중에 하위 클래스로 만들고 중첩시킬거임.

void CEquipment::Create_Armor(char* _pName, int _iRank, int _iReqLv, int _iHp, int _iPrice, int _iCount, bool _isEquiped)
{
	strcpy_s(m_EQObject.m_szName, sizeof(m_EQObject.m_szName), _pName);
	m_EQObject.m_iRank = _iRank;
	m_EQObject.m_iReqLv = _iReqLv;
	m_EQObject.m_iAttack = NULL;
	m_EQObject.m_iHp = _iHp;
	m_EQObject.m_iPrice = _iPrice;
	m_EQObject.m_iCount = _iCount;
	m_EQObject.m_isEquiped = _isEquiped;
}

CEquipment::CEquipment(int _iRank, bool _isWeapon)
{
	m_EQObject.m_iRank = _iRank; // 1,2,3
	if (_isWeapon)
	{
		switch (m_EQObject.m_iRank)
		{
		case 1:
			Create_Weapon("초급무기", 1, 1, 10, 10, 1, false);
			break;
		case 2:
			Create_Weapon("중급무기", 2, 5, 20, 30, 1, false);
			break;
		case 3:
			Create_Weapon("고급무기", 3, 10, 30, 50, 1, false);
			break;

		default:
			break;
		}
	}
	else
	{
		switch (m_EQObject.m_iRank)
		{
		case 1:
			Create_Armor("초급방어구", 1, 1, 10, 10, 1, false);
			break;
		case 2:
			Create_Armor("중급방어구", 2, 5, 30, 30, 1, false);
			break;
		case 3:
			Create_Armor("고급방어구", 3, 10, 50, 50, 1, false);
			break;

		default:
			break;
		}
	}

}


CEquipment::~CEquipment()
{

}
