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
		cout << "���� �׺�" << endl;
		cout << "1. ���� ���� 2. �� �ܰ� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (0 == m_pPlayer->GET_INFO().m_iGold)
			{
				cout << "�������� �����մϴ�." << endl;
				system("pause");
			}
			else
			{
				cout << "�ǵ��� �Է����ּ��� : ";
				cin >> iGambleGold;
				if (iGambleGold > m_NPCGold)
				{
					cout << "NPC : ������ ���ư�." << endl;
					system("pause");
					return;
				}

				if (iGambleGold > m_pPlayer->GET_INFO().m_iGold)
				{
					cout << "�������� �����մϴ�." << endl;
					system("pause");
				}
				else
				{
					m_NPCGold -= iGambleGold; // NPC �ǵ�
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
	cout << "�ǵ� : " << _iGold * 2 << " - �¸��ϸ� ȹ�� "<< endl;
	cout << "������ : " << m_pPlayer->GET_INFO().m_iGold << "\t\t\t\t\t������ : " << m_NPCGold << endl; // ������ �Լ��� ó��
	cout << "���� : " << _isPlayerBingo << "\t\t\t\t\t���� : " << _isNPCBingo << endl;
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
	for (int i = 0; i < 5; ++i) // ����
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

	for (int i = 0; i < 5; ++i) // ����
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

	for (int i = 0; i < 5; ++i) // �밢
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
	

	// Player ������ �ʱ�ȭ
	int iPlayer_Bingo[m_iSize][m_iSize] = {};
	Init_Bingo(iPlayer_Bingo, m_iSize);

	// NPC ������ �ʱ�ȭ
	int iNPC_Bingo[m_iSize][m_iSize] = {};
	Init_Bingo(iNPC_Bingo, m_iSize);


	// �������� üũ�ؼ� 4���� �κ��� ������ �� �κ��� ���� �����ͼ� 
	// ������ �� ������ ó���ϴ� ������� �����ϸ� ������

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

		cout << "NPC�� ������ �� : " << iNPC_rand << endl;

		cout << "1~25 �߿� �� ���� : ";
		cin >> iInput;
		
		// input �� ����� üũ
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
			cout << "�й�" << endl;
			cout << "NPC�� " << _iGold * 2 << "��ŭ ��带 ȹ���մϴ�." << endl;
			system("pause");

			m_NPCGold += _iGold * 2;
			return;
		}
		else if (5 <= isPlayerBingo)
		{
			cout << "�¸�" << endl;
			cout << "�÷��̾ " << _iGold * 2 << "��ŭ ��带 ȹ���մϴ�." << endl;
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