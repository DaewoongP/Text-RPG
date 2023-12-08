#include "stdafx.h"
#include "Monster.h"

void CMonster::Initialize()
{
}

void CMonster::Update()
{
}

void CMonster::Release()
{
}

CMonster::CMonster(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		Create_Object("�ʱ�", 30, 3, 1, 1, 0, 10);
		break;

	case 2:
		Create_Object("�߱�", 60, 6, 3, 2, 0, 20);
		break;

	case 3:
		Create_Object("���", 90, 9, 5, 3, 0, 30);
		break;

	default:
		cout << "�������� ���� ����" << endl;
		return;
	}
}


CMonster::~CMonster()
{
}

void CMonster::Render(void)
{
	cout << "==========================================" << endl;
	cout << "�̸� : " << m_Object.m_szName << "\t������ : " << m_Object.m_iGold << endl;
	cout << "���� : " << m_Object.m_iLevel << "\t����ġ : " << m_Object.m_iExp << endl;
	cout << "ü�� : " << m_Object.m_iHp << " / " << m_Object.m_iMaxHp << "\t���ݷ� : " << m_Object.m_iAttack << endl;
	cout << "==========================================" << endl;
}

// ������Ʈ ���� : �÷��̾�����, �̸�, ü��, ���ݷ�, ���, ����, �ִ����ġ, ����ġ
void CMonster::Create_Object(char * _pName, int _iMaxHp, int _iAttack, int _iGold, int _iLevel, int _iMaxExp, int _iExp)
{
	strcpy_s(m_Object.m_szName, sizeof(m_Object.m_szName), _pName);
	m_Object.m_iMaxHp = _iMaxHp;
	m_Object.m_iHp = m_Object.m_iMaxHp;
	m_Object.m_iAttack = _iAttack;
	m_Object.m_iExp = _iExp;
	m_Object.m_iGold = _iGold; // ��� ġƮŰ��
	m_Object.m_iLevel = _iLevel;
	m_Object.m_iMaxExp = _iMaxExp;
}