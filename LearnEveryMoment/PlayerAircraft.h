#pragma once
#include "Aircraft.h"

class CPlayerAircraft :	public CAircraft
{
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	void MoveAircraft(DIR8 dir);

public:
	CPlayerAircraft();
	virtual ~CPlayerAircraft();
};

