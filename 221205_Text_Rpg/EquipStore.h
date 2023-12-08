#pragma once
#include "Player.h"
#include "Define.h"
#include "Equipment.h"

class CEquipStore
{
public:
	void	Initialize();
	void	Update();
	void	Release();

	void	SET_Player(CObj* _Player) { m_pPlayer = _Player; }

public:
	
	CEquipStore();
	~CEquipStore();
private:
	CObj*		m_pPlayer;
};

