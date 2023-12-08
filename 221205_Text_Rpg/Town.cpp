#include "stdafx.h"
#include "Town.h"


void CTown::Initialize()
{
	m_pField = new CField;	// �ʵ� �����Ҵ�
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
		cout << "����" << endl;
		cout << "0. �κ��丮 1. ����� 2. ȸ������ 3. ������ 4. ���� �׺� 5. �޴��� �̵� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 0:
			dynamic_cast<CPlayer*>(m_pPlayer)->GET_Inventory();
			break;
		case FIELD:
			m_pField->Initialize();
			m_pField->SET_Player(m_pPlayer); // �ʵ忡 �÷��̾ ��������.
			m_pField->Update(); // �ʵ� �̵�
			
			break;

		case 2:
			m_pPotionStore->Initialize();
			m_pPotionStore->SET_Player(m_pPlayer); // ȸ�������� �÷��̾� ����
			m_pPotionStore->Update(); // ȸ�� ���� �̵�
			cout << "ȸ������ ��ġ��" << endl;
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
			m_pGamble->Update(); // ���� �׺� �̵�
			
			break;

		case 5:
			dynamic_cast<CPlayer*>(m_pPlayer)->Release();
			Release();
			return;

		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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