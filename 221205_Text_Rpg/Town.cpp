#include "stdafx.h"
#include "Town.h"


void CTown::Initialize()
{
	m_pField = new CField;	// 필드 동적할당
	m_pPotionStore = new CPotionStore;
	m_pEquipStore = new CEquipStore;
	m_pGamble = new CGamble;
}

void CTown::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "Text RPG" << endl;
		m_pPlayer->Render();
		cout << "마을" << endl;
		cout << "0. 인벤토리 1. 사냥터 2. 회복상점 3. 장비상점 4. 빙고 겜블 5. 메뉴로 이동 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 0:
			dynamic_cast<CPlayer*>(m_pPlayer)->GET_Inventory();
			break;
		case FIELD:
			m_pField->Initialize();
			m_pField->SET_Player(m_pPlayer); // 필드에 플레이어를 복사해줌.
			m_pField->Update(); // 필드 이동
			
			break;

		case 2:
			m_pPotionStore->Initialize();
			m_pPotionStore->SET_Player(m_pPlayer); // 회복상점에 플레이어 복사
			m_pPotionStore->Update(); // 회복 상점 이동
			cout << "회복상점 패치중" << endl;
			system("pause");
			break;
		case 3:
			m_pEquipStore->Initialize();
			m_pEquipStore->SET_Player(m_pPlayer);
			m_pEquipStore->Update();
			break;

		case 4:
			m_pGamble->Initialize();
			m_pGamble->SET_Player(m_pPlayer);
			m_pGamble->Update(); // 빙고 겜블 이동
			
			break;

		case 5:
			dynamic_cast<CPlayer*>(m_pPlayer)->Release();
			Release();
			return;

		default:
			cout << "잘못입력하셨습니다." << endl;
			system("pause");
			break;
		}
	}
}

void CTown::Release()
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPotionStore);
	SAFE_DELETE(m_pEquipStore);
	SAFE_DELETE(m_pGamble);
}

CTown::CTown()
{
	m_pField = nullptr;
	m_pGamble = nullptr;
	m_pEquipStore = nullptr;
	m_pPotionStore = nullptr;
}


CTown::~CTown()
{
	Release();
}