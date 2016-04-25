#include "stdafx.h"
#include "Data_Moving.h"

CData_Moving::CData_Moving()
{
}

CData_Moving::CData_Moving(D3DXVECTOR3 DestPos, float DurationTime)
	:m_DestPos(DestPos), m_DurationTime(DurationTime)
{
}

CData_Moving::~CData_Moving()
{
}

void CData_Moving::setTime(float inputTime)
{
	m_DurationTime = inputTime;
}

void CData_Moving::setPos_Dest(D3DXVECTOR3 inputVec)
{
	m_DestPos = inputVec;
}
