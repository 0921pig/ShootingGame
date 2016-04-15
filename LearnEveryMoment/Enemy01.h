#pragma once
#include "EnemyAircraft.h"
#include "MovingCoursePattern.h"

class CObj;

class CEnemy01 : public CEnemyAircraft
{
private:
	CMovingCoursePattern m_MovingCourseList;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	CEnemy01();
	virtual ~CEnemy01();
};

