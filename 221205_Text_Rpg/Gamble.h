#pragma once
#include "Player.h"

class CGamble
{
public:
	void	Initialize();
	void	Update();
	void	Release();

	void	Render_Info(int _iGold, int _isPlayerBingo, int _isNPCBingo);
	void	Render_Bingo(int _Player_Bingo[5][5], int _NPC_Bingo[5][5], int _iSize);					
	void	Init_Bingo(int iBingo[5][5], int _iSize);
	int		Chk_Bingo(int iBingo[5][5]);
	void	SET_Player(CObj* _Player) { m_pPlayer = _Player; }

	void	Bingo(int _iGold);

public:
	CGamble();
	~CGamble();


private:
	CObj*	m_pPlayer;
	static int	m_NPCGold;
};