#pragma once
#include "Include.h"

class CMovingPattern;
class CAttackPattern;

class CPatternMgr
{
	DECLARE_SINGLETON(CPatternMgr);

private:
	map<MovingPattern_Type, CMovingPattern*> m_MovingPatternList;
	map<AttackPattern_Type, CAttackPattern*> m_AttackPatternList;

public:
	void initialize();
	void init_registerMovingPattern();
	void init_registerAttackPattern();

	CMovingPattern* GetMovingPattern(MovingPattern_Type MovingType);
	CAttackPattern* GetAttackPattern(AttackPattern_Type AttackType);
	
public:
	CPatternMgr();
	~CPatternMgr();
};
