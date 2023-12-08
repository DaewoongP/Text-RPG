#pragma once
#include "Define.h"
#include "Equipment.h"
#include "Potion.h"
class CObj;

class CInventory
{
public:
	void Initialize();
	void Update();
	void Release();

	void Render();

	void SET_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	void SET_Count(int _iCount);


	void Equip_Item(int _iItem_No);

	bool SET_Item(CItem* _newItem);
	void SET_isEquiped(int _iItem_No, bool _isEquiped);

	void SET_Equip_Weapon_No(int _iNum) { m_iEquip_Weapon_No = _iNum; }
	void SET_Equip_Armor_No(int _iNum) { m_iEquip_Armor_No = _iNum; }

	int GET_Count() { return m_iCount; }
	int GET_Equip_Weapon_No() { return m_iEquip_Weapon_No; }
	int GET_Equip_Armor_No() { return m_iEquip_Armor_No; }
	CItem* GET_Item(int _iItem_No) { return m_pItem[_iItem_No]; }

public:
	CInventory();
	~CInventory();

private:
	CObj*		m_pPlayer;

	CItem*		m_pItem[20];

	static int	m_iCount;

	static int	m_iEquip_Weapon_No;
	static int  m_iEquip_Armor_No;

};

