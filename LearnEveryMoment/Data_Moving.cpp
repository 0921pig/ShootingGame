#include "stdafx.h"
#include "Data_Moving.h"

CData_Moving::CData_Moving()
{
}

CData_Moving::~CData_Moving()
{
}

void CData_Moving::setTime(float inputTime)
{
	m_fTime = inputTime;
}

void CData_Moving::setPos_Start(D3DXVECTOR3 inputVec)
{
	m_StartPos = inputVec;
}

void CData_Moving::setPos_Arrive(D3DXVECTOR3 inputVec)
{
	m_ArrivePos = inputVec;
}
