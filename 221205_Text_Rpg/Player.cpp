#include "stdafx.h"
#include "Player.h"

void CPlayer::Initialize()
{
	Select_Job(); // 직업 할당
	m_pInventory = new CInventory; // 플레이어 인벤토리 동적할당
	m_pInventory->Initialize();
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	SAFE_DELETE(m_pInventory);
	m_pWeapon = nullptr; // 댕글린 포인터 방지 (인벤토리 내에서 모든 아이템을 삭제하기 때문.)
	m_pArmor = nullptr;
}

void CPlayer::Render(void)
{
	cout << "==========================================" << endl;
	cout << "이름 : " << m_Object.m_szName << "\t소지금 : " << m_Object.m_iGold << endl;
	cout << "레벨 : " << m_Object.m_iLevel << "\t경험치 : " << m_Object.m_iExp << " / " << m_Object.m_iMaxExp << endl;
	cout << "체력 : " << m_Object.m_iHp << " / " << m_Object.m_iMaxHp << "\t공격력 : " << m_Object.m_iAttack << endl;
	cout << "무기 : " << m_szWeapon << "\t방어구 : " << m_szArmor << endl;
	cout << "==========================================" << endl;
}

// 오브젝트 생성 : 플레이어판정, 이름, 체력, 공격력, 골드, 레벨, 최대경험치, 경험치
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
		// 방어구 해제 시 체력이 해제 한 후보다 많을경우
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

			if (!strcmp(m_Object.m_szName, "전사"))
			{
				m_Object.m_iMaxHp += 10;
				m_Object.m_iHp = m_Object.m_iMaxHp;
				m_Object.m_iAttack += 5;
				m_Object.m_iMaxExp += 10;

			}
			else if (!strcmp(m_Object.m_szName, "마법사"))
			{
				m_Object.m_iMaxHp += 5;
				m_Object.m_iHp = m_Object.m_iMaxHp;
				m_Object.m_iAttack += 10;
				m_Object.m_iMaxExp += 10;
			}
			else if (!strcmp(m_Object.m_szName, "도적"))
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
		cout << "직업을 선택해주세요 (1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		// 직업의 초기값 설정
		switch (iInput)
		{
		case WARRIOR:
			Create_Object("전사", 100, 10, 0, 1, 100, 0);
			return;

		case MAGE:
			Create_Object("마법사", 90, 8, 0, 1, 100, 0);
			return;

		case ROGUE:
			Create_Object("도적", 95, 10, 0, 1, 100, 0);
			return;

		default:
			cout << "잘못입력하셨습니다." << endl;
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
		cout << "인벤토리" << endl;
		Render();
		cout << "1. 장비 2. 소비 3. 전 단계: " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pInventory->Render();
			cout << "장착할 아이템 : ";
			cin >> iItem_No;
			// 레벨제한 확인
			if (m_pInventory->GET_Item(iItem_No)->GET_Info().m_iReqLv > GET_INFO().m_iLevel)
			{
				cout << "장착하기에 레벨이 너무 낮습니다." << endl;
				cout << "필요 레벨 제한 : " << m_pInventory->GET_Item(iItem_No)->GET_Info().m_iReqLv << endl;
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
	// 나중에 세트화 해제를 위해 무기, 방어구 따로 처리
	m_pWeapon = new CEquipment(_iInput, true);
	m_pArmor = new CEquipment(_iInput, false);

	if (m_pWeapon->GET_Info().m_iPrice + m_pArmor->GET_Info().m_iPrice > GET_INFO().m_iGold)
	{
		cout << "골드가 부족합니다." << endl;
		SAFE_DELETE(m_pWeapon);
		SAFE_DELETE(m_pArmor);
		system("pause");
		return;
	}
	else // 소지금 감소
	{
		SET_Gold(m_pWeapon->GET_Info().m_iPrice + m_pArmor->GET_Info().m_iPrice, false);
		cout << "장비를 구매하였습니다." << endl;
		system("pause");
	}

	if (m_pInventory->SET_Item(m_pWeapon)) // 중복이 있을경우
		SAFE_DELETE(m_pWeapon);
	if (m_pInventory->SET_Item(m_pArmor))
		SAFE_DELETE(m_pArmor);
}

void CPlayer::Equip_Item(int _iItem_No)
{
	if (!(_iItem_No % 2)) // 무기
	{
		if (!m_pInventory->GET_Item(_iItem_No)->GET_Info().m_isEquiped)
		{
			if (m_pInventory->GET_Equip_Weapon_No() != -1) // 3번끼려는데 5번이 껴져있다면 장착해제부터
			{
				Render_Weapon("X");
				SET_Attack(m_pInventory->GET_Item(m_pInventory->GET_Equip_Weapon_No())->GET_Info().m_iAttack, false);
				m_pInventory->SET_isEquiped(m_pInventory->GET_Equip_Weapon_No(), false);

			}
			// 장비 장착
			m_pInventory->SET_Equip_Weapon_No(_iItem_No);
			Render_Weapon(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName);
			SET_Attack(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iAttack);
			m_pInventory->SET_isEquiped(_iItem_No, true);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " 장착 성공" << endl;
		}
		else
		{
			// 장비 장착 해제
			m_pInventory->SET_Equip_Weapon_No(-1);
			Render_Weapon("X");
			SET_Attack(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iAttack, false);
			m_pInventory->SET_isEquiped(_iItem_No, false);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " 장착 해제" << endl;
		}
	}
	else if (_iItem_No % 2) // 방어구
	{
		if (!m_pInventory->GET_Item(_iItem_No)->GET_Info().m_isEquiped)
		{
			if (m_pInventory->GET_Equip_Armor_No() != -1) // 3번끼려는데 5번이 껴져있다면 장착해제부터
			{
				Render_Armor("X");
				SET_MaxHp(m_pInventory->GET_Item(m_pInventory->GET_Equip_Armor_No())->GET_Info().m_iHp, false);
				m_pInventory->SET_isEquiped(m_pInventory->GET_Equip_Armor_No(), false);

			}
			// 장비 장착
			m_pInventory->SET_Equip_Armor_No(_iItem_No);
			Render_Armor(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName);
			SET_MaxHp(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iHp);
			m_pInventory->SET_isEquiped(_iItem_No, true);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " 장착 성공" << endl;

		}
		else
		{
			// 장비 장착 해제
			m_pInventory->SET_Equip_Armor_No(-1);
			Render_Armor("X");
			SET_MaxHp(m_pInventory->GET_Item(_iItem_No)->GET_Info().m_iHp, false);
			m_pInventory->SET_isEquiped(_iItem_No, false);
			cout << m_pInventory->GET_Item(_iItem_No)->GET_Info().m_szName << " 장착 해제" << endl;
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
