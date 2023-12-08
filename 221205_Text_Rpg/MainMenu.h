#pragma once
#include "Town.h"
#include "SaveManager.h"
#include "Player.h"

class CMainMenu
{
public:
	void Initialize();
	void Update();
	void Release();

public:
	CMainMenu();
	~CMainMenu();

private:
	CObj*			m_pPlayer;
	CMyMap*			m_pTown;
	CSaveManager	m_SaveManager;
};

