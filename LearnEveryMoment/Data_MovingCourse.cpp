#include "stdafx.h"
#include "Data_MovingCourse.h"

CData_MovingCourse::CData_MovingCourse()
{
}


CData_MovingCourse::~CData_MovingCourse()
{
}

void CData_MovingCourse::setTime(float inputTime)
{
	m_fTime = inputTime;
}

void CData_MovingCourse::setPos_Start(D3DXVECTOR3 inputVec)
{
	m_StartPos = inputVec;
}

void CData_MovingCourse::setPos_Arrive(D3DXVECTOR3 inputVec)
{
	m_ArrivePos = inputVec;
}
