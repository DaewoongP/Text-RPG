#include "stdafx.h"
#include "SaveManager.h"

void CSaveManager::Save_File(CObj* _pPlayer)
{
	// ĳ������ �⺻ ������ �����ؾ��Ѵ�.
	// ���̳ʸ� ���·� ����
	FILE* pFile_Write = nullptr;

	errno_t err = fopen_s(&pFile_Write, "../Save/Save.txt", "wb");

	if (0 == err) // ������ �߸� �����̹Ƿ� 0�϶� ���� ����
	{
		fwrite(_pPlayer, sizeof(CObj), 1, pFile_Write);
		
		cout << "ĳ���� ���� ���� ����!" << endl;

		fclose(pFile_Write);
	}
	else
		cout << "ĳ���� ���� ���� ����" << endl;
}

CObj* CSaveManager::Load_File(CObj* Load_Player)
{
	//CPlayer* _Player = new CPlayer;
	FILE* pFile_Read = nullptr;

	errno_t err = fopen_s(&pFile_Read, "../Save/Save.txt", "rb");

	if (0 == err) // ������ �߸� �����̹Ƿ� 0�϶� ���� ����
	{
		fread(Load_Player, sizeof(CObj), 1, pFile_Read);
		
		fclose(pFile_Read);
	}
	else
		cout << "ĳ���� ���� �ҷ����� ����" << endl;

	return Load_Player;
}

CSaveManager::CSaveManager()
{
}


CSaveManager::~CSaveManager()
{
}
