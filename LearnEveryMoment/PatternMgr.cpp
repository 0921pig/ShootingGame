#include "stdafx.h"
#include "Include.h"

CPatternMgr::CPatternMgr()
{
}

CPatternMgr::~CPatternMgr()
{
}

void CPatternMgr::initialize()
{
	init_registerMovingPattern();
	init_registerAttackPattern();
}

void CPatternMgr::init_registerMovingPattern()
{
	CMovingPattern* pTargetPattern = NULL;

	/* Vertical Basic 01 */
	pTargetPattern = new CMovingPattern();
	pTargetPattern->add_MovingSchedule(D3DXVECTOR3(0.f, +300.f, 0.f), 1000.f);
	pTargetPattern->add_MovingSchedule(D3DXVECTOR3(0.f, 0.f, 0.f), 1000.f);
	pTargetPattern->add_MovingSchedule(D3DXVECTOR3(0.f, -300.f, 0.f), 1000.f);
	m_MovingPatternList.insert(make_pair(MovingType_Basic_01, pTargetPattern));
	


}

void CPatternMgr::init_registerAttackPattern()
{
	CAttackPattern* pTargetPattern = NULL;

	/* Vertical Basic 01 */
	pTargetPattern = new CAttackPattern();
	m_AttackPatternList.insert(make_pair(AttackType_Basic_01, pTargetPattern));
}

CMovingPattern* CPatternMgr::GetMovingPattern(MovingPattern_Type MovingType)
{
	if (m_MovingPatternList.size() <= 0)
	{
		TRACE(L"GetMovingPattern 중에 m_MovingPatternList의 사이즈가 0\n");
		return NULL;
	}

	map<MovingPattern_Type, CMovingPattern*> ::iterator iter = m_MovingPatternList.find(MovingType);
	if (iter == m_MovingPatternList.end())
	{
		TRACE(L"CPatternMgr에서 GetMovingPattern 중에 패턴을 찾지 못했다n");
		return NULL;
	}

	CMovingPattern* pattern = new CMovingPattern(*iter->second);
	return pattern;
}

CAttackPattern* CPatternMgr::GetAttackPattern(AttackPattern_Type AttackType)
{
	if (m_AttackPatternList.size() <= 0)
	{
		TRACE(L"GetMovingPattern 중에 m_AttackPatternList의 사이즈가 0\n");
		return NULL;
	}
	
	map<AttackPattern_Type, CAttackPattern*> ::iterator iter = m_AttackPatternList.find(AttackType);
	if (iter == m_AttackPatternList.end())
	{
		TRACE(L"CPatternMgr에서 GetAttackPattern 중에 패턴을 찾지 못했다\n");
		return NULL;
	}

	CAttackPattern* pattern = new CAttackPattern(*iter->second);
	return pattern;
}
