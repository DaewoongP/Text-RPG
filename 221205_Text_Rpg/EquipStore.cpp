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
		cout << "장비 상점" << endl;
		m_pPlayer->Render();
		cout << "1. 초급 장비(20골드) 2. 중급 장비(60골드) 3. 고급 장비(100골드) 4. 전 단계 : ";
		cin >> iInput;

		if (4 > iInput)
			dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Equipment(iInput);// 플레이어가 아이템 구매.
		else if (4 == iInput)
			return;
		else
		{
			cout << "잘못입력하셨습니다." << endl;
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
