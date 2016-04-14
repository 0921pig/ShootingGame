#pragma once
#include "Obj.h"

class CAircraft : public CObj 
{
private:
	float m_Speed;

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	virtual void MoveAircraft(DIR8 dir);
	float getSpeed();
	void setSpeed(float inputSpeed);

public:
	CAircraft();
	virtual ~CAircraft();
};

