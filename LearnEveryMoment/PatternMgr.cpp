#include "stdafx.h"
#include "Include.h"

CPatternMgr::CPatternMgr()
{
}

CPatternMgr::~CPatternMgr()
{
}

void CPatternMgr::Initialize()
{
	init_registerMovingPattern();
}

void CPatternMgr::init_registerMovingPattern()
{
	CMovingPattern* pTargetPattern = NULL;

	/* Vertical Basic 01 */
	pTargetPattern = new CMovingPattern();
	pTargetPattern->add_MovingSchedule(D3DXVECTOR3(0.f, +300.f, 0.f), 1000.f);
	pTargetPattern->add_MovingSchedule(D3DXVECTOR3(0.f, -300.f, 0.f), 1000.f);


}

CMovingPattern* CPatternMgr::GetMovingPattern(MovingPattern_Type MovingType)
{
	map<MovingPattern_Type, CMovingPattern*> :: iterator iter =  m_MovingPatternList.find(MovingType);
	if (iter->second == NULL)
	{
		TRACE(L"CPatternMgr에서 GetMovingPattern 중에 에러 발생\n");
		return NULL;
	}
	
	CMovingPattern* pattern = new CMovingPattern(*iter->second);
	return pattern;
}

CAttackPattern* CPatternMgr::GetAttackPattern(AttackPattern_Type AttackType)
{
	map<AttackPattern_Type, CAttackPattern*> ::iterator iter = m_AttackPatternList.find(AttackType);
	if (iter->second == NULL)
	{
		TRACE(L"CPatternMgr에서 GetAttackPattern 중에 에러 발생\n");
		return NULL;
	}

	CAttackPattern* pattern = new CAttackPattern(*iter->second);
	return pattern;
}
