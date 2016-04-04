#include "stdafx.h"
#include "Data_Fire.h"


CData_Fire::CData_Fire()
{
}


CData_Fire::~CData_Fire()
{
}


void CData_Fire::setAccel(D3DXVECTOR3 inputAccel)
{
	m_Accel = inputAccel;
}

void CData_Fire::setVelocity(D3DXVECTOR3 inputVelocity)
{
	m_Velocity = inputVelocity;
}

void CData_Fire::setTime(float inputTime)
{
	m_fTime = inputTime;
}
