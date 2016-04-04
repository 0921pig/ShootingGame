#pragma once
#include "Obj.h"

enum PlayableAircraft;

class CSelect_Aircraft : public CObj
{
private:
	bool isRandom;
	PlayableAircraft m_Aircraft;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

private:
	void change_AircraftName(PlayableAircraft AircraftName);

public:
	CSelect_Aircraft(PlayableAircraft aircraft);
	virtual ~CSelect_Aircraft();
};

enum PlayableAircraft
{
	PA_Harrier,
	PA_Stealth,
	PA_Raptor,
	PA_Phantom,
	PA_SuperHornet,
	PA_Random
};
