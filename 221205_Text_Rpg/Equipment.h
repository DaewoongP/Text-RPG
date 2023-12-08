#pragma once
#include "Define.h"
#include "Item.h"

class CEquipment : public CItem
{
public:
	void Initialize();
	void Update();
	void Release();

	void Create_Weapon(char* _pName, int _iRank, int _iReqLv, int _iAttack, int _iPrice, int _iCount, bool _isEquiped);
	void Create_Armor(char* _pName, int _iRank, int _iReqLv, int _iAttack, int _iPrice, int _iCount, bool _isEquiped);

	void SET_isEquiped(bool _isEquiped) { m_EQObject.m_isEquiped = _isEquiped; }

public:
	CEquipment() {}
	CEquipment(int _iRank, bool _isWeapon);


	~CEquipment();
private:
	
};

