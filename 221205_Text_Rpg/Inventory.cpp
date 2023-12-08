#include "stdafx.h"
#include "Inventory.h"
#include "Player.h"

int CInventory::m_iCount = 0;
int CInventory::m_iEquip_Weapon_No = -1;
int CInventory::m_iEquip_Armor_No = -1;

void CInventory::Initialize()
{
	SET_Count(0);
}

void CInventory::Update()
{

}

void CInventory::Release()
{
	for (int i = 0; i < m_iCount; ++i)
	{
		SAFE_DELETE(m_pItem[i])
	}
}

void CInventory::Render()
{
	cout << "==========================================" << endl;
	for (int i = 0; i < m_iCount; ++i)
	{
		cout << i << ". ";
		m_pItem[i]->Render();
	}
	cout << "==========================================" << endl;
}

void CInventory::SET_Count(int _iCount)
{
	m_iCount = _iCount;
}

void CInventory::Equip_Item(int _iItem_No)
{
	if (!(_iItem_No % 2)) // 무기
	{
		if (!m_pItem[_iItem_No]->GET_Info().m_isEquiped)
		{
			if (m_iEquip_Weapon_No != -1) // 3번끼려는데 5번이 껴져있다면 장착해제부터
			{
				static_cast<CPlayer*>(m_pPlayer)->Render_Weapon("X");
				static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[m_iEquip_Weapon_No]->GET_Info().m_iAttack, false);
				dynamic_cast<CEquipment*>(m_pItem[m_iEquip_Weapon_No])->SET_isEquiped(false);

			}
			// 장비 장착
			m_iEquip_Weapon_No = _iItem_No;
			static_cast<CPlayer*>(m_pPlayer)->Render_Weapon(m_pItem[_iItem_No]->GET_Info().m_szName);
			static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[_iItem_No]->GET_Info().m_iAttack);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(true);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " 장착 성공" << endl;
		}
		else
		{
			// 장비 장착 해제
			m_iEquip_Weapon_No = -1;
			static_cast<CPlayer*>(m_pPlayer)->Render_Weapon("X");
			static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[_iItem_No]->GET_Info().m_iAttack, false);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(false);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " 장착 해제" << endl;
		}
	}
	else if (_iItem_No % 2) // 방어구
	{
		if (!m_pItem[_iItem_No]->GET_Info().m_isEquiped)
		{
			if (m_iEquip_Armor_No != -1) // 3번끼려는데 5번이 껴져있다면 장착해제부터
			{
				static_cast<CPlayer*>(m_pPlayer)->Render_Armor("X");
				static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[m_iEquip_Armor_No]->GET_Info().m_iHp, false);
				dynamic_cast<CEquipment*>(m_pItem[m_iEquip_Armor_No])->SET_isEquiped(false);

			}
			// 장비 장착
			m_iEquip_Armor_No = _iItem_No;
			static_cast<CPlayer*>(m_pPlayer)->Render_Armor(m_pItem[_iItem_No]->GET_Info().m_szName);
			static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[_iItem_No]->GET_Info().m_iHp);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(true);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " 장착 성공" << endl;

		}
		else
		{
			// 장비 장착 해제
			m_iEquip_Armor_No = -1;
			static_cast<CPlayer*>(m_pPlayer)->Render_Armor("X");
			static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[_iItem_No]->GET_Info().m_iHp, false);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(false);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " 장착 해제" << endl;
		}
	}
	system("pause");

}

bool CInventory::SET_Item(CItem * _newItem) // 인벤토리에 구매한 아이템 세팅
{
	for (int i = 0; i < m_iCount; ++i) // 중복아이템 체크
	{
		if (!strcmp(m_pItem[i]->GET_Info().m_szName, _newItem->GET_Info().m_szName))
		{
			// 중복이 있을시 그 아이템 수량을 늘리고 true 반환 
			m_pItem[i]->SET_Count(1); // 아이템 수량
			return true;
		}
	}
	// 신규아이템일 경우 false 반환
	m_pItem[m_iCount] = _newItem;
	
	++m_iCount;
	return false;
}

void CInventory::SET_isEquiped(int _iItem_No, bool _isEquiped)
{
	dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(_isEquiped);
}

CInventory::CInventory()
	
{
	memset(m_pItem, 0, sizeof(m_pItem));
}


CInventory::~CInventory()
{
	Release();
}