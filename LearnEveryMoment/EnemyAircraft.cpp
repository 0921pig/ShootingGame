#include "stdafx.h"
#include "Include.h"

CEnemyAircraft::CEnemyAircraft()
{
}


CEnemyAircraft::~CEnemyAircraft()
{
}

void CEnemyAircraft::applyPattern(CMovingPattern* MovePattern, CAttackPattern* AttackPattern)
{
	/* MovePattern 등록 */
	if (MovePattern != NULL)
		m_MovingPattern = MovePattern;
	else
		TRACE(L"applyPattern() Moving Pattern에 NULL이 들어옴\n");

	/* AttackPattern 등록 */
	if (AttackPattern != NULL)
		m_AttackPattern = AttackPattern;
	else
		TRACE(L"applyPattern() Attack Pattern에 NULL이 들어옴\n");
}