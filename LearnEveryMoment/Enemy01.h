#pragma once
#include "EnemyAircraft.h"

class CObj;

class CEnemy01 : public CEnemyAircraft
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	CEnemy01();
	virtual ~CEnemy01();
};

