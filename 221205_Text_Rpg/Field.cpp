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
		cout << "�����" << endl;
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iInput;
		if (4 > iInput && 0 < iInput)
		{
			// �ʵ��� ���̵� ���� �� ���� �����Ҵ�
			// �����ڿ��� input ���� ���� ���͸� �����Ѵ�.
			m_pMonster = new CMonster(iInput);
			// �����Ҵ��� ���Ϳ� ��Ʋ
			Battle();
			// �����Ҵ��� ���� �����Ҵ� ����
			SAFE_DELETE(m_pMonster);
		}

		else if (4 == iInput)
			return;

		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
		cout << "1. ���� 2. ���� : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			// ������ ü���� ����. (������ �������� �����ϴ� ����)
			m_pPlayer->SET_Damage(m_pMonster->GET_INFO().m_iAttack);
			m_pMonster->SET_Damage(m_pPlayer->GET_INFO().m_iAttack);

			//*m_pPlayer -= *m_pMonster;
			//*m_pMonster -= *m_pPlayer;

			// Hp�� ���� ���
			if (0 >= m_pPlayer->GET_INFO().m_iHp)
			{
				cout << "�÷��̾� ���" << endl;
				cout << "�������� ���� ����ġ�� �ҽ��ϴ�." << endl;
				// 1~5 �������� ������ ����
				srand(unsigned(time(NULL)));
				int iMinGold = (rand() % 5) + 1;
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(iMinGold, false);
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Hp(m_pPlayer->GET_INFO().m_iMaxHp);
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Exp(50, false);

				system("pause");
				return;
			}
			// Hp�� ���� ���
			if (0 >= m_pMonster->GET_INFO().m_iHp)
			{
				cout << "�¸�" << endl;
				cout << m_pMonster->GET_INFO().m_iGold << "��� ��ŭ ȹ���ϼ̽��ϴ�." << endl;
				// ��� �߰�
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Gold(m_pMonster->GET_INFO().m_iGold);
				// ����ġ �߰�
				dynamic_cast<CPlayer*>(m_pPlayer)->SET_Exp(m_pMonster->GET_INFO().m_iExp);
				system("pause");
				return;
			}
			break;

		case 2:
			return;

		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
