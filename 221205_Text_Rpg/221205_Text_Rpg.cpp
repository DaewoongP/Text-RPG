#include "stdafx.h"
#include "Define.h"
#include "MainMenu.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CMainMenu		MainMenu;

	MainMenu.Initialize(); // �ʱ�ȭ
	MainMenu.Update(); // �����Լ�


    return 0;
}

