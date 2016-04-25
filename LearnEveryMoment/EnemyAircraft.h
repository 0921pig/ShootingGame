#pragma once
#include "Aircraft.h"

class CMovingPattern;
class CAttackPattern;

class CEnemyAircraft :	public CAircraft
{
private:
	CMovingPattern* m_MovingPattern;
	CAttackPattern* m_AttackPattern;

public:
	void applyPattern(CMovingPattern* MovePattern, CAttackPattern* AttackPattern);

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