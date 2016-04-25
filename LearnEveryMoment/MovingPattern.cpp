#include "stdafx.h"
#include "MovingPattern.h"


CMovingPattern::CMovingPattern()
{
}

CMovingPattern::~CMovingPattern()
{
}

void CMovingPattern::convert_RelativeToAbsolute(D3DXVECTOR3 startPos)
{
	D3DXVECTOR3 vCurrentPos = startPos;

	for (list<CData_Moving> ::iterator iter = m_MovingList.begin(); iter != m_MovingList.end(); ++iter)
	{
		iter->setPos_Dest(startPos + iter->getPos_Dest());
		startPos = iter->getPos_Dest();
	}
}

void CMovingPattern::add_MovingSchedule(D3DXVECTOR3 DestPos_Relative, float durationTime)
{
	m_MovingList.push_back(CData_Moving(DestPos_Relative, durationTime));
}
