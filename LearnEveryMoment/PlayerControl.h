#pragma once
#include "Obj.h"

class CAircraft;

class CPlayerControl : public CObj
{
private:
	CPlayer_Belonging* m_Belonging;
	CAircraft* m_Aircraft;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	void setBelonging(CPlayer_Belonging* inputBelonging);
	CAircraft* getAircraft();
	void setAircraft(CAircraft* inputAircraft);

public:
	CPlayerControl(AircraftTypeOfPlayer Name);
	virtual ~CPlayerControl();
};

