#include "stdafx.h"
#include "Gamble.h"

int CGamble::m_NPCGold = 2000;

void CGamble::Initialize()
{
	m_pPlayer = nullptr;
}

void CGamble::Update()
{
	while (true)
	{
		int iInput = 0;
		int	iGambleGold = 0;
		system("cls");
		m_pPlayer->Render();
		cout << "빙고 겜블" << endl;
		cout << "1. 게임 시작 2. 전 단계 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (0 == m_pPlayer->GET_INFO().m_iGold)
			{
				cout << "소지금이 부족합니다." << endl;
				system("pause");
			}
			else
			{
				cout << "판돈을 입력해주세요 : ";
				cin >> iGambleGold;
				if (iGambleGold > m_NPCGold)
				{
					cout << "NPC : 돈없어 돌아가." << endl;
					system("pause");
					return;
				}

				if (iGambleGold > m_pPlayer->GET_INFO().m_iGold)
				{
					cout << "소지금이 부족합니다." << endl;
					system("pause");
				}
				else
				{
					m_NPCGold -= iGambleGold; // NPC 판돈
					dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(iGambleGold, false);
					Bingo(iGambleGold);
				}
			}
				
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

void CGamble::Release()
{
	
}

void CGamble::Render_Info(int _iGold, int _isPlayerBingo, int _isNPCBingo)
{
	cout << "====================================================================================" << endl;
	cout << "Player\t\t\t\t\t\tNPC" << endl;
	cout << "판돈 : " << _iGold * 2 << " - 승리하면 획득 "<< endl;
	cout << "소지금 : " << m_pPlayer->GET_INFO().m_iGold << "\t\t\t\t\t소지금 : " << m_NPCGold << endl; // 소지금 함수로 처리
	cout << "빙고 : " << _isPlayerBingo << "\t\t\t\t\t빙고 : " << _isNPCBingo << endl;
	cout << "====================================================================================" << endl;
}

void CGamble::Render_Bingo(int _Player_Bingo[5][5], int _NPC_Bingo[5][5], int _iSize)
{
	for (int i = 0; i < _iSize; ++i)
	{
		for (int j = 0; j < _iSize; ++j)
		{
			if (999 != _Player_Bingo[i][j])
				cout << _Player_Bingo[i][j] << "\t";
			else
				cout << "*\t";
		}
		cout << "|\t";
		for (int j = 0; j < _iSize; ++j)
		{
			if (999 != _NPC_Bingo[i][j])
				cout << _NPC_Bingo[i][j] << "\t";
			else
				cout << "*\t";
		}
		cout << endl;
	}
}

void CGamble::Init_Bingo(int iBingo[5][5], int _iSize)
{
	int iTemp = 0, iDest = 0, iSour = 0;
	int iArray[5][5] = {};

	for (int i = 0; i < _iSize; ++i) {
		for (int j = 0; j < _iSize; ++j)
		{
			iArray[i][j] = (5 * i) + j + 1;
		}
	}

	for (int i = 0; i < 500; ++i)
	{
		iTemp = rand() % 5;
		iDest = rand() % 5;
		for (int j = 0; j < 5; ++j) {
			iSour = iArray[j][iTemp];
			iArray[j][iTemp] = iArray[iDest][j];
			iArray[iDest][j] = iSour;
		}
		for (int j = 0; j < 5; ++j) {
			iSour = iArray[iTemp][j];
			iArray[iTemp][j] = iArray[j][iDest];
			iArray[j][iDest] = iSour;
		}
	}

	for (int i = 0; i < _iSize; ++i)
	{
		for (int j = 0; j < _iSize; ++j)
		{
			iBingo[i][j] = iArray[i][j];
		}
	}

}

int CGamble::Chk_Bingo(int iBingo[5][5])
{
	int iCnt = 0;
	int IsBingo = 0;
	for (int i = 0; i < 5; ++i) // 가로
	{
		for (int j = 0; j < 5; ++j)
		{
			if (999 == iBingo[i][j])
				++iCnt;
			if (5 == iCnt)
				++IsBingo;
		}
		iCnt = 0;
	}

	for (int i = 0; i < 5; ++i) // 세로
	{
		for (int j = 0; j < 5; ++j)
		{
			if (999 == iBingo[j][i])
				++iCnt;
			if (5 == iCnt)
				++IsBingo;
		}
		iCnt = 0;
	}

	for (int i = 0; i < 5; ++i) // 대각
	{
		for (int j = 0; j < 5; ++j)
		{
			if (4 == i + j)
			{
				if (999 == iBingo[i][j])
					++iCnt;
				if (5 == iCnt)
					++IsBingo;
			}
		}
	}
	iCnt = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (999 == iBingo[i][i])
			++iCnt;
		if (5 == iCnt)
			++IsBingo;
	}
	iCnt = 0;
	return IsBingo;
}

void CGamble::Bingo(int _iGold)
{

	const int	m_iSize = 5;
	int		isPlayerBingo = 0;
	int		isNPCBingo = 0;
	int		iNPC_rand = 0;
	int		iChk_rand = 0;
	

	// Player 빙고판 초기화
	int iPlayer_Bingo[m_iSize][m_iSize] = {};
	Init_Bingo(iPlayer_Bingo, m_iSize);

	// NPC 빙고판 초기화
	int iNPC_Bingo[m_iSize][m_iSize] = {};
	Init_Bingo(iNPC_Bingo, m_iSize);


	// 빙고판을 체크해서 4개인 부분이 있으면 그 부분의 값을 가져와서 
	// 다음에 그 값으로 처리하는 방식으로 제작하면 어려울듯

	while (true)
	{
		srand(unsigned(time(NULL)));
		int iInput = 0;
		while (true) {
			iNPC_rand = rand() % 25 + 1;
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (iNPC_rand == iNPC_Bingo[i][j])
					{
						++iChk_rand;
					}
				}

			}
			if (iChk_rand)
				break;
		}
		iChk_rand = 0;

		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNPC_rand == iPlayer_Bingo[i][j])
					iPlayer_Bingo[i][j] = 999;
				if (iNPC_rand == iNPC_Bingo[i][j])
					iNPC_Bingo[i][j] = 999;
			}
		
		}
		
		Render_Info(_iGold, isPlayerBingo, isNPCBingo);

		Render_Bingo(iPlayer_Bingo, iNPC_Bingo, m_iSize);

		isPlayerBingo = Chk_Bingo(iPlayer_Bingo);
		isNPCBingo = Chk_Bingo(iNPC_Bingo);

		cout << "NPC가 선택한 값 : " << iNPC_rand << endl;

		cout << "1~25 중에 값 선택 : ";
		cin >> iInput;
		
		// input 값 빙고로 체크
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iInput == iPlayer_Bingo[i][j])
					iPlayer_Bingo[i][j] = 999;
				if (iInput == iNPC_Bingo[i][j])
					iNPC_Bingo[i][j] = 999;
			}
		}

		isPlayerBingo = Chk_Bingo(iPlayer_Bingo);
		isNPCBingo = Chk_Bingo(iNPC_Bingo);

		if (5 <= isNPCBingo)
		{
			cout << "패배" << endl;
			cout << "NPC가 " << _iGold * 2 << "만큼 골드를 획득합니다." << endl;
			system("pause");

			m_NPCGold += _iGold * 2;
			return;
		}
		else if (5 <= isPlayerBingo)
		{
			cout << "승리" << endl;
			cout << "플레이어가 " << _iGold * 2 << "만큼 골드를 획득합니다." << endl;
			system("pause");

			dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(_iGold * 2);
			return;
		}

	}
}

CGamble::CGamble()
{
	Initialize();
}

CGamble::~CGamble()
{
	Release();
}