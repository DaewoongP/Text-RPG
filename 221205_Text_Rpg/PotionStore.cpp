#include "stdafx.h"
#include "PotionStore.h"


void CPotionStore::Initialize()
{

}

void CPotionStore::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "���� ����" << endl;
		m_pPlayer->Render();
		cout << "1. 100% ȸ�� ���� (5) 2. 50% ȸ�� ���� (3) 3. �� �ܰ� : ";
		cin >> iInput;

		if (3 > iInput)
			dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Potion(iInput);// �÷��̾ ������ ����.
		else if (4 == iInput)
			return;
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			system("pause");
		}


	}
}

void CPotionStore::Release()
{
}


CPotionStore::CPotionStore()
{
	m_pPlayer = nullptr;
}

	
CPotionStore::~CPotionStore()
{
}