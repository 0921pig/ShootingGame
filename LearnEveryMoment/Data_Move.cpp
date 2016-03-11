#include "stdafx.h"
#include "Data_Move.h"

CData_Move::CData_Move()
{
}


CData_Move::~CData_Move()
{
}

void CData_Move::setTime(float inputTime)
{
	m_fTime = inputTime;
}

void CData_Move::setPos_Start(D3DXVECTOR3 inputVec)
{
	m_StartPos = inputVec;
}

void CData_Move::setPos_Arrive(D3DXVECTOR3 inputVec)
{
	m_ArrivePos = inputVec;
}
