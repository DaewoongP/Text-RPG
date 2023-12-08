#include "stdafx.h"
#include "Player.h"

void CPlayer::Initialize()
{
	Select_Job(); // ���� �Ҵ�
	m_pInventory = new CInventory; // �÷��̾� �κ��丮 �����Ҵ�
	m_pInventory->Initialize();
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	SAFE_DELETE(m_pInventory);
	m_pWeapon = nullptr; // ��۸� ������ ���� (�κ��丮 ������ ��� �������� �����ϱ� ����.)
	m_pArmor = nullptr;
}

void CPlayer::Render(void)
{
	cout << "==========================================" << endl;
	cout << "�̸� : " << m_Object.m_szName << "\t������ : " << m_Object.m_iGold << endl;
	cout << "���� : " << m_Object.m_iLevel << "\t����ġ : " << m_Object.m_iExp << " / " << m_Object.m_iMaxExp << endl;
	cout << "ü�� : " << m_Object.m_iHp << " / " << m_Object.m_iMaxHp << "\t���ݷ� : " << m_Object.m_iAttack << endl;
	cout << "���� : " << m_szWeapon << "\t�� : " << m_szArmor << endl;
	cout << "==========================================" << endl;
}

// ������Ʈ ���� : �÷��̾�����, �̸�, ü��, ���ݷ�, ���, ����, �ִ����ġ, ����ġ
void CPlayer::Create_Object(char * _pName, int _iMaxHp, int _iAttack, int _iGold, int _iLevel, int _iMaxExp, int _iExp)
{
	strcpy_s(m_Object.m_szName, sizeof(m_Object.m_szName), _pName);
	m_Object.m_iMaxHp = _iMaxHp;
	m_Object.m_iHp = m_Object.m_iMaxHp;
	m_Object.m_iAttack = _iAttack;
	m_Object.m_iExp = _iExp;
	m_Object.m_iGold = 5000;
	m_Object.m_iLevel = _iLevel;
	m_Object.m_iMaxExp = _iMaxExp;
}

void CPlayer::SET_Hp(int _iHp)
{
	m_Object.m_iHp = _iHp;
}

void CPlayer::SET_MaxHp(int _iMaxHp, bool isPlus)
{
	if (isPlus)
		m_Object.m_iMaxHp += _iMaxHp;
	else
	{
		m_Object.m_iMaxHp -= _iMaxHp;
		// �� ���� �� ü���� ���� �� �ĺ��� �������
		if (m_Object.m_iMaxHp < m_Object.m_iHp)
			m_Object.m_iHp = m_Object.m_iMaxHp;
	}
}

void CPlayer::SET_Attack(int _iAttack, bool isPlus)
{
	if (isPlus)
		m_Object.m_iAttack += _iAttack;
	else
		m_Object.m_iAttack -= _iAttack;
}

void CPlayer::SET_Gold(int _iGold, bool isPlus)
{
	if (isPlus)
		m_Object.m_iGold += _iGold;
	else
	{
		m_Object.m_iGold -= _iGold;
		if (0 > m_Object.m_iGold)
			m_Object.m_iGold = 0;
	}

}

void CPlayer::Render_Weapon(char * _szWeapon)
{
	strcpy_s(m_szWeapon, sizeof(m_szWeapon), _szWeapon);
}

void CPlayer::Render_Armor(char * _szArmor)
{
	strcpy_s(m_szArmor, sizeof(m_szArmor), _szArmor);
}

void CPlayer::SET_Exp(int _iExp, bool isPlus)
{
	if (isPlus)
	{
		m_Object.m_iExp += _iExp;
		if (m_Object.m_iMaxExp <= m_Object.m_iExp)
		{
			++m_Object.m_iLevel;
			m_Object.m_iExp -= m_Object.m_iMaxExp;

			if (!strcmp(m_Object.m_szName, "����"))
			{
				m_Object.m_iMaxHp += 10;
				m_Object.m_iHp = m_Object.m_iMaxHp;
				m_Object.m_iAttack += 5;
				m_Object.m_iMaxExp += 10;

			}
			else if (!strcmp(m_Object.m_szName, "������"))
			{
				m_Object.m_iMaxHp += 5;
				m_Object.m_iHp = m_Object.m_iMaxHp;
				m_Object.m_iAttack += 10;
				m_Object.m_iMaxExp += 10;
			}
			else if (!strcmp(m_Object.m_szName, "����"))
			{
				m_Object.m_iMaxHp += 8;
				m_Object.m_iHp = m_Object.m_iMaxHp;
				m_Object.m_iAttack += 8;
				m_Object.m_iMaxExp += 10;
			}
		}
	}
	else
	{
		m_Object.m_iExp -= _iExp;
		if (0 > m_Object.m_iExp)
			m_Object.m_iExp = 0;
	}


}

void CPlayer::Select_Job(void)
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "������ �������ּ��� (1. ���� 2. ������ 3. ����) : ";
		cin >> iInput;
		// ������ �ʱⰪ ����
		switch (iInput)
		{
		case WARRIOR:
			Create_Object("����", 100, 10, 0, 1, 100, 0);
			return;

		case MAGE:
			Create_Object("������", 90, 8, 0, 1, 100, 0);
			return;

		case ROGUE:
			Create_Object("����", 95, 10, 0, 1, 100, 0);
			return;

		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			system("pause");
			break;
		}
	}
}

void CPlayer::GET_Inventory()
{
	while (true)
	{
		int iInput = 0;
		int iItem_No = 0;
		system("cls");
		cout << "�κ��丮" << endl;
		Render();
		cout << "1. ��� 2. �Һ� 3. �� �ܰ�: " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pInventory->Render();
			cout << "������ ������ : ";
			cin >> iItem_No;
			// �������� Ȯ��
			if (m_pInventory->GET_Item(iItem_No)->GET_Info().m_iReqLv > GET_INFO().m_iLevel)
			{
				cout << "�����ϱ⿡ ������ �ʹ� �����ϴ�." << endl;
				cout << "�ʿ� ���� ���� : " << m_pInventory->GET_Item(iItem_No)->GET_Info().m_iReqLv << endl;
				system("pause");
			}
			else
				Equip_Item(iItem_No);
			break;
		case 2:
			break;
		case 3:
			return;
		default:
			break;
		}

	}
}

void CPlayer::Buy_Equipment(int _iInput)
{
	// ���߿� ��Ʈȭ ������ ���� ����, �� ���� ó��
	m_pWeapon = new CEquipment(_iInput, true);
	m_pArmor = new CEquipment(_iInput, false);

	if (m_pWeapon->GET_Info().m_iPrice + m_pArmor->GET_Info().m_iPrice > GET_INFO().m_iGold)
	{
		cout << "��尡 �����մϴ�." << endl;
		SAFE_DELETE(m_pWeapon);
		SAFE_DELETE(m_pArmor);
		system("pause");
		return;
	}
	else // ������ ����
	{
		SET_Gold(m_pWeapon->GET_Info().m_iPrice + m_pArmor->GET_Info().m_iPrice, false);
		cout << "��� �����Ͽ����ϴ�." << endl;
		system("pause");
	}

	if (m_pInventory->SET_Item(m_pWeapon)) // �ߺ��� �������
		SAFE_DELETE(m_pWeapon);
	if (m_pInventory->SET_Item(m_pArmor))
		SAFE_DELETE(m_pArmor);
}

void CPlayer::Equip_Item(int _iItem_No)
{
	if (!(_iItem_No % 2)) // ����
	{
		if (!m_pInventory->GET_Item(_iItem_No)->GET_Info().m_isEquiped)
		{
			if (m_pInventory->GET_Equip_Weapon_No() != -1) // 3�������µ� 5���� �����ִٸ� ������������
			{
				Render_Weapon("X");
				SET_Attack(m_pInventory->GET_Item(m_pInventory->GET_Equip_Weapon_No())->GET_Info().m_iAttack, false);
				m_pInventory->SET_isEquiped(m_pInventory->GET_Equip_Weapon_No(), false);

			}
			// ��� ����
			m_pInventory->SET_Equip_Weapon_No(_iItem_No);
			Render_Weapon(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName);
			SET_Attack(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iAttack);
			m_pInventory->SET_isEquiped(_iItem_No, true);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " ���� ����" << endl;
		}
		else
		{
			// ��� ���� ����
			m_pInventory->SET_Equip_Weapon_No(-1);
			Render_Weapon("X");
			SET_Attack(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iAttack, false);
			m_pInventory->SET_isEquiped(_iItem_No, false);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " ���� ����" << endl;
		}
	}
	else if (_iItem_No % 2) // ��
	{
		if (!m_pInventory->GET_Item(_iItem_No)->GET_Info().m_isEquiped)
		{
			if (m_pInventory->GET_Equip_Armor_No() != -1) // 3�������µ� 5���� �����ִٸ� ������������
			{
				Render_Armor("X");
				SET_MaxHp(m_pInventory->GET_Item(m_pInventory->GET_Equip_Armor_No())->GET_Info().m_iHp, false);
				m_pInventory->SET_isEquiped(m_pInventory->GET_Equip_Armor_No(), false);

			}
			// ��� ����
			m_pInventory->SET_Equip_Armor_No(_iItem_No);
			Render_Armor(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName);
			SET_MaxHp(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iHp);
			m_pInventory->SET_isEquiped(_iItem_No, true);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " ���� ����" << endl;

		}
		else
		{
			// ��� ���� ����
			m_pInventory->SET_Equip_Armor_No(-1);
			Render_Armor("X");
			SET_MaxHp(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iHp, false);
			m_pInventory->SET_isEquiped(_iItem_No, false);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " ���� ����" << endl;
		}
	}
	system("pause");

}

void CPlayer::Buy_Potion(int _iInput)
{
	m_pPotion = new CPotion;
	SAFE_DELETE(m_pPotion);
}


CPlayer::CPlayer()
{
	strcpy_s(m_szWeapon, sizeof(m_szWeapon), "X");
	strcpy_s(m_szArmor, sizeof(m_szArmor), "X");
	m_pWeapon = nullptr;
	m_pArmor = nullptr;
	m_pPotion = nullptr;
	m_pInventory = nullptr;
}


CPlayer::~CPlayer()
{
	Release();
}
