#include "stdafx.h"
#include "Item.h"

int CItem::m_iAllCount = 0;

void CItem::Render()
{
	cout << "�̸� : " << m_EQObject.m_szName << endl;
	cout << "   ���� : " << m_EQObject.m_iCount << endl;
}

CItem::CItem()
{
	memset(&m_EQObject, 0, sizeof(m_EQObject));
	++m_iAllCount; // ������ ��ü������ ���ͼ� �κ��丮�� ���� ����
}


CItem::~CItem()
{
}
