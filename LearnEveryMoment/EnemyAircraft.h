#pragma once
#include "Aircraft.h"

class CMovingPattern;

class CEnemyAircraft :	public CAircraft
{
private:
	CMovingPattern* m_MovingList;

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

