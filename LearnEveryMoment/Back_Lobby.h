#pragma once

#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

#ifndef HEADER_Obj
	#define HEADER_Obj
	#include "Obj.h"
#endif

typedef struct PHYSICS_Base
{
	float position_current;
	float position_goal;
	float distance_forStop;
	float distance_toGoal;
	float speed_max;
	float speed_cur;
	float acceleration;
	
	PHYSICS_Base()
		:position_current(0.f),	position_goal(0.f), distance_forStop(0.f), distance_toGoal(0.f), speed_max(0.f), speed_cur(0.f), acceleration(0.f)
	{
	}
}PHYSICS_Base;

class CBack_Lobby :	public CObj
{
private:
	bool isMoving_NumberBack;
	PHYSICS_Base m_NumberBack;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	void moveNumberBack(PlayableAircraft inputAircraft);

public:
	CBack_Lobby();
	virtual ~CBack_Lobby();
};

