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
		cout << "포션 상점" << endl;
		m_pPlayer->Render();
		cout << "1. 100% 회복 물약 (5) 2. 50% 회복 물약 (3) 3. 전 단계 : ";
		cin >> iInput;

		if (3 > iInput)
			dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Potion(iInput);// 플레이어가 아이템 구매.
		else if (4 == iInput)
			return;
		else
		{
			cout << "잘못입력하셨습니다." << endl;
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