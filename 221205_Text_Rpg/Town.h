#pragma once
#include "MyMap.h"
#include "Field.h"
#include "PotionStore.h"
#include "EquipStore.h"
#include "Gamble.h"

class CTown : public CMyMap
{
public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	CTown();
	virtual ~CTown();

private:
	CField*			m_pField;
	CPotionStore*	m_pPotionStore;
	CGamble*		m_pGamble;
	CEquipStore*	m_pEquipStore;
};

