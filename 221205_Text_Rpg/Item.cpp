#include "stdafx.h"
#include "Item.h"

int CItem::m_iAllCount = 0;

void CItem::Render()
{
	cout << "이름 : " << m_EQObject.m_szName << endl;
	cout << "   개수 : " << m_EQObject.m_iCount << endl;
}

CItem::CItem()
{
	memset(&m_EQObject, 0, sizeof(m_EQObject));
	++m_iAllCount; // 아이템 전체개수를 빼와서 인벤토리에 담을 예정
}


CItem::~CItem()
{
}
