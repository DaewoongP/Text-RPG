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
		Create_Object("초급", 30, 3, 1, 1, 0, 10);
		break;

	case 2:
		Create_Object("중급", 60, 6, 3, 2, 0, 20);
		break;

	case 3:
		Create_Object("고급", 90, 9, 5, 3, 0, 30);
		break;

	default:
		cout << "스테이지 선택 오류" << endl;
		return;
	}
}


CMonster::~CMonster()
{
}

void CMonster::Render(void)
{
	cout << "==========================================" << endl;
	cout << "이름 : " << m_Object.m_szName << "\t소지금 : " << m_Object.m_iGold << endl;
	cout << "레벨 : " << m_Object.m_iLevel << "\t경험치 : " << m_Object.m_iExp << endl;
	cout << "체력 : " << m_Object.m_iHp << " / " << m_Object.m_iMaxHp << "\t공격력 : " << m_Object.m_iAttack << endl;
	cout << "==========================================" << endl;
}

// 오브젝트 생성 : 플레이어판정, 이름, 체력, 공격력, 골드, 레벨, 최대경험치, 경험치
void CMonster::Create_Object(char * _pName, int _iMaxHp, int _iAttack, int _iGold, int _iLevel, int _iMaxExp, int _iExp)
{
	strcpy_s(m_Object.m_szName, sizeof(m_Object.m_szName), _pName);
	m_Object.m_iMaxHp = _iMaxHp;
	m_Object.m_iHp = m_Object.m_iMaxHp;
	m_Object.m_iAttack = _iAttack;
	m_Object.m_iExp = _iExp;
	m_Object.m_iGold = _iGold; // 잠깐 치트키좀
	m_Object.m_iLevel = _iLevel;
	m_Object.m_iMaxExp = _iMaxExp;
}