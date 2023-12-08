#include "stdafx.h"
#include "SaveManager.h"

void CSaveManager::Save_File(CObj* _pPlayer)
{
	// 캐릭터의 기본 정보를 저장해야한다.
	// 바이너리 형태로 은닉
	FILE* pFile_Write = nullptr;

	errno_t err = fopen_s(&pFile_Write, "../Save/Save.txt", "wb");

	if (0 == err) // 에러가 뜨면 음수이므로 0일때 개방 성공
	{
		fwrite(_pPlayer, sizeof(CObj), 1, pFile_Write);
		
		cout << "캐릭터 정보 저장 성공!" << endl;

		fclose(pFile_Write);
	}
	else
		cout << "캐릭터 정보 저장 실패" << endl;
}

CObj* CSaveManager::Load_File(CObj* Load_Player)
{
	//CPlayer* _Player = new CPlayer;
	FILE* pFile_Read = nullptr;

	errno_t err = fopen_s(&pFile_Read, "../Save/Save.txt", "rb");

	if (0 == err) // 에러가 뜨면 음수이므로 0일때 개방 성공
	{
		fread(Load_Player, sizeof(CObj), 1, pFile_Read);
		
		fclose(pFile_Read);
	}
	else
		cout << "캐릭터 정보 불러오기 실패" << endl;

	return Load_Player;
}

CSaveManager::CSaveManager()
{
}


CSaveManager::~CSaveManager()
{
}
