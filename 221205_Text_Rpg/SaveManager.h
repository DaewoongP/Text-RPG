#pragma once
#include "Obj.h"

class CSaveManager
{
public:
	void Save_File(CObj* _pPlayer);
	CObj* Load_File(CObj* Load_Player);

public:
	CSaveManager();
	~CSaveManager();
};

