#include "stdafx.h"
#include "MainMenu.h"

void CMainMenu::Initialize()
{
	// town field -> ���� Ŭ������
	m_pPlayer = new CPlayer;
	m_pTown = new CTown; // ���� �����Ҵ�
}

void CMainMenu::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "Text RPG" << endl;
		cout << "1. �� ���� 2. �ҷ����� 3. �����ϱ� 4. ���� ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case NEWGAME:
			m_pTown->SET_Player(m_pPlayer); // �÷��̾� �ּҰ��� �������� ������(�÷��̾� �����)
			dynamic_cast<CPlayer*>(m_pPlayer)->Initialize(); // ���ο� �����̹Ƿ� ĳ���� ����
			// ���� ����
			m_pTown->Initialize();
			m_pTown->Update();
			break;

		case LOADGAME:
			// �����Ҵ��� ĳ���Ϳ� �ε������� �����
			m_pTown->SET_Player(m_SaveManager.Load_File(m_pPlayer));
			m_pTown->Update(); // ���� ���� ����
			break;

		case 3:
			m_SaveManager.Save_File(m_pPlayer);
			system("pause");
			break;

		case 4:
			return;

		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			system("pause");
			break;
		}

	}
}

void CMainMenu::Release()
{
	//SAFE_DELETE(m_pPlayer);
	Safe_Delete<CObj*>(m_pPlayer);
	SAFE_DELETE(m_pTown);
	
}

CMainMenu::CMainMenu()
{
	m_pPlayer = nullptr;
	m_pTown = nullptr;
}


CMainMenu::~CMainMenu()
{
	Release();
}
