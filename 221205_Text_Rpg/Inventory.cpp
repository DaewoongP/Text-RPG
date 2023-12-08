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
	if (!(_iItem_No % 2)) // ����
	{
		if (!m_pItem[_iItem_No]->GET_Info().m_isEquiped)
		{
			if (m_iEquip_Weapon_No != -1) // 3�������µ� 5���� �����ִٸ� ������������
			{
				static_cast<CPlayer*>(m_pPlayer)->Render_Weapon("X");
				static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[m_iEquip_Weapon_No]->GET_Info().m_iAttack, false);
				dynamic_cast<CEquipment*>(m_pItem[m_iEquip_Weapon_No])->SET_isEquiped(false);

			}
			// ��� ����
			m_iEquip_Weapon_No = _iItem_No;
			static_cast<CPlayer*>(m_pPlayer)->Render_Weapon(m_pItem[_iItem_No]->GET_Info().m_szName);
			static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[_iItem_No]->GET_Info().m_iAttack);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(true);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " ���� ����" << endl;
		}
		else
		{
			// ��� ���� ����
			m_iEquip_Weapon_No = -1;
			static_cast<CPlayer*>(m_pPlayer)->Render_Weapon("X");
			static_cast<CPlayer*>(m_pPlayer)->SET_Attack(m_pItem[_iItem_No]->GET_Info().m_iAttack, false);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(false);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " ���� ����" << endl;
		}
	}
	else if (_iItem_No % 2) // ��
	{
		if (!m_pItem[_iItem_No]->GET_Info().m_isEquiped)
		{
			if (m_iEquip_Armor_No != -1) // 3�������µ� 5���� �����ִٸ� ������������
			{
				static_cast<CPlayer*>(m_pPlayer)->Render_Armor("X");
				static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[m_iEquip_Armor_No]->GET_Info().m_iHp, false);
				dynamic_cast<CEquipment*>(m_pItem[m_iEquip_Armor_No])->SET_isEquiped(false);

			}
			// ��� ����
			m_iEquip_Armor_No = _iItem_No;
			static_cast<CPlayer*>(m_pPlayer)->Render_Armor(m_pItem[_iItem_No]->GET_Info().m_szName);
			static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[_iItem_No]->GET_Info().m_iHp);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(true);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " ���� ����" << endl;

		}
		else
		{
			// ��� ���� ����
			m_iEquip_Armor_No = -1;
			static_cast<CPlayer*>(m_pPlayer)->Render_Armor("X");
			static_cast<CPlayer*>(m_pPlayer)->SET_MaxHp(m_pItem[_iItem_No]->GET_Info().m_iHp, false);
			dynamic_cast<CEquipment*>(m_pItem[_iItem_No])->SET_isEquiped(false);
			cout << m_pItem[_iItem_No]->GET_Info().m_szName << " ���� ����" << endl;
		}
	}
	system("pause");

}

bool CInventory::SET_Item(CItem * _newItem) // �κ��丮�� ������ ������ ����
{
	for (int i = 0; i < m_iCount; ++i) // �ߺ������� üũ
	{
		if (!strcmp(m_pItem[i]->GET_Info().m_szName, _newItem->GET_Info().m_szName))
		{
			// �ߺ��� ������ �� ������ ������ �ø��� true ��ȯ 
			m_pItem[i]->SET_Count(1); // ������ ����
			return true;
		}
	}
	// �űԾ������� ��� false ��ȯ
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