#pragma once
#include "Define.h"
#include "Obj.h"
#include "Item.h"
#include "Inventory.h"

class CPlayer : public CObj
{
public:
	void	Initialize();
	void	Update();
	void	Release();

	virtual void	Render(void);

	virtual void	Create_Object(char* _pName, int _iMaxHp, int _iAttack,
		int _iGold, int _iLevel, int _iMaxExp, int _iExp);

	void	Select_Job(void);

	void	SET_Hp(int _iHp);
	void	SET_MaxHp(int _iMaxHp, bool isPlus = true);
	void	SET_Attack(int _iAttack, bool isPlus = true);
	void	SET_Exp(int _iExp, bool isPlus = true);
	void	SET_Gold(int _iGold , bool isPlus = true);

	void	GET_Inventory();
	
	void	Buy_Equipment(int _iInput);
	void	Equip_Item(int _iItem_No);

	void	Buy_Potion(int _iInput);
	
public:
	// 이름 세팅
	void	Render_Weapon(char* _szWeapon);
	void	Render_Armor(char* _szArmor);

public:
	CPlayer();
	~CPlayer();

private:
	char		m_szWeapon[32];
	char		m_szArmor[32];

	CItem*		m_pWeapon;
	CItem*		m_pArmor;

	CItem*		m_pPotion;

	CInventory*	m_pInventory;

};

