#include "stdafx.h"
#include "Field.h"

void CField::Initialize()
{
}

void CField::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "Text RPG" << endl;
		m_pPlayer->Render();
		cout << "사냥터" << endl;
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;
		if (4 > iInput && 0 < iInput)
		{
			// 필드의 난이도 선택 시 몬스터 동적할당
			// 생성자에서 input 값에 따라 몬스터를 생성한다.
			m_pMonster = new CMonster(iInput);
			// 동적할당한 몬스터와 배틀
			Battle();
			// 동적할당한 몬스터 동적할당 해제
			SAFE_DELETE(m_pMonster);
		}

		else if (4 == iInput)
			return;

		else
		{
			cout << "잘못입력하셨습니다." << endl;
			system("pause");
		}
	}
}

void CField::Release()
{
	SAFE_DELETE(m_pMonster);
}

void CField::Battle()
{
	while (true) {
		int iInput = 0;
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			// 서로의 체력을 깎음. (서로의 데미지를 세팅하는 느낌)
			m_pPlayer->SET_Damage(m_pMonster->GET_INFO().m_iAttack);
			m_pMonster->SET_Damage(m_pPlayer->GET_INFO().m_iAttack);

			//*m_pPlayer -= *m_pMonster;
			//*m_pMonster -= *m_pPlayer;

			// Hp에 따른 결과
			if (0 >= m_pPlayer->GET_INFO().m_iHp)
			{
				cout << "플레이어 사망" << endl;
				cout << "일정량의 골드와 경험치를 잃습니다." << endl;
				// 1~5 랜덤으로 소지금 증발
				srand(unsigned(time(NULL)));
				int iMinGold = (rand() % 5) + 1;
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(iMinGold, false);
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Hp(m_pPlayer->GET_INFO().m_iMaxHp);
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Exp(50, false);

				system("pause");
				return;
			}
			// Hp에 따른 결과
			if (0 >= m_pMonster->GET_INFO().m_iHp)
			{
				cout << "승리" << endl;
				cout << m_pMonster->GET_INFO().m_iGold << "골드 만큼 획득하셨습니다." << endl;
				// 골드 추가
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(m_pMonster->GET_INFO().m_iGold);
				// 경험치 추가
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Exp(m_pMonster->GET_INFO().m_iExp);
				system("pause");
				return;
			}
			break;

		case 2:
			return;

		default:
			cout << "잘못입력하셨습니다." << endl;
			system("pause");
			break;
		}
	}
}

CField::CField()
	:m_pMonster(nullptr)
{
	
}


CField::~CField()
{
	Release();
}
