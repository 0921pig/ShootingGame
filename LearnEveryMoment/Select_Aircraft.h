#pragma once
#ifndef HEADER_Obj
	#define HEADER_Obj
	#include "Obj.h"
#endif

class CSelect_Aircraft : public CObj
{
private:
	bool isRandom;
	PlayableAircraft m_Aircraft;

	bool isSelected;
	CInfo_Obj m_CursorSelecting;

	CInfo_Obj m_BigPicture;
	CInfo_Obj m_WeaponInfo;
	CInfo_Obj m_FighterCode;
	CInfo_Obj m_FighterCode_Shadow;
	CInfo_Obj m_FighterNickname;
	CInfo_Obj m_FighterNickname_Shadow;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

private:
	void change_AircraftName(PlayableAircraft AircraftName);
	void init_calculateMatrix();

public:
	CSelect_Aircraft(PlayableAircraft aircraft);
	void select(bool val);
	virtual ~CSelect_Aircraft();
};

