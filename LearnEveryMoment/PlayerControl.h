#pragma once
#include "Obj.h"

class CPlayerAircraft;

class CPlayerControl : public CObj
{
private:
	CPlayer_Belonging* m_Belonging;
	CPlayerAircraft* m_PlayerAircraft;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	void setBelonging(CPlayer_Belonging* inputBelonging);
	CPlayerAircraft* getPlayerAircraft();
	void setPlayerAircraft(CPlayerAircraft* inputAircraft);

public:
	CPlayerControl(AircraftTypeOfPlayer Name);
	virtual ~CPlayerControl();
};

