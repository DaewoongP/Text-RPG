#include "stdafx.h"
#include "MainMenu.h"

void CMainMenu::Initialize()
{
	// town field -> 상위 클래스로
	m_pPlayer = new CPlayer;
	m_pTown = new CTown; // 게임 동적할당
}

void CMainMenu::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "Text RPG" << endl;
		cout << "1. 새 게임 2. 불러오기 3. 저장하기 4. 게임 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case NEWGAME:
			m_pTown->SET_Player(m_pPlayer); // 플레이어 주소값을 게임으로 가져감(플레이어 복사용)
			dynamic_cast<CPlayer*>(m_pPlayer)->Initialize(); // 새로운 게임이므로 캐릭터 선택
			// 마을 진입
			m_pTown->Initialize();
			m_pTown->Update();
			break;

		case LOADGAME:
			// 동적할당한 캐릭터에 로드파일을 덮어씌움
			m_pTown->SET_Player(m_SaveManager.Load_File(m_pPlayer));
			m_pTown->Update(); // 메인 게임 진입
			break;

		case 3:
			m_SaveManager.Save_File(m_pPlayer);
			system("pause");
			break;

		case 4:
			return;

		default:
			cout << "잘못입력하셨습니다." << endl;
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
