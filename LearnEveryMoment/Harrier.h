#pragma once
#include "Aircraft.h"

class CHarrier : public CPlayerAircraft
{

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:

public:
	CHarrier();
	virtual ~CHarrier();
};

