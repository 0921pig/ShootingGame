#pragma once
#include "Include.h"

enum AttackPattern_Type;
enum MovingPattern_Type;

class CPatternMgr
{
	DECLARE_SINGLETON(CPatternMgr);

private:
	map<MovingPattern_Type, CMovingPattern*> m_MovingPatternList;
	map<AttackPattern_Type, CAttackPattern*> m_AttackPatternList;

public:
	void Initialize();
	CMovingPattern* GetMovingPattern(MovingPattern_Type MovingType);
	CAttackPattern* GetAttackPattern(AttackPattern_Type AttackType);
	
public:
	CPatternMgr();
	~CPatternMgr();
};

enum AttackPattern_Type
{
	Basic_01
};

enum MovingPattern_Type
{
	Basic_01
};