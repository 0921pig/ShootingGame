#pragma once
#include "Aircraft.h"
class CEnemyAircraft :	public CAircraft
{

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	CEnemyAircraft();
	virtual ~CEnemyAircraft();
};

