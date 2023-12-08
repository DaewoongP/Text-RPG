#pragma once
#include "Player.h"

class CPotionStore
{
public:
	void Initialize();
	void Update();
	void Release();

	void	SET_Player(CObj* _Player) { m_pPlayer = _Player; }

public:
	CPotionStore();
	~CPotionStore();

private:
	CObj*		m_pPlayer;

};