#include "stdafx.h"
#include "EquipStore.h"


void CEquipStore::Initialize()
{
	
}

void CEquipStore::Update()
{
	while (true)
	{
		int iInput = 0;
		system("cls");
		cout << "��� ����" << endl;
		m_pPlayer->Render();
		cout << "1. �ʱ� ���(20���) 2. �߱� ���(60���) 3. ��� ���(100���) 4. �� �ܰ� : ";
		cin >> iInput;

		if (4 > iInput)
			dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Equipment(iInput);// �÷��̾ ������ ����.
		else if (4 == iInput)
			return;
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			system("pause");
		}
	}
}

void CEquipStore::Release()
{
	
}

CEquipStore::CEquipStore()
{
	m_pPlayer = nullptr;

}


CEquipStore::~CEquipStore()
{
	Release();
}
