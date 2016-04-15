#include "stdafx.h"
#include "Data_Attack.h"


CData_Attack::CData_Attack()
{
}


CData_Attack::~CData_Attack()
{
}


void CData_Attack::setAccel(D3DXVECTOR3 inputAccel)
{
	m_Accel = inputAccel;
}

void CData_Attack::setVelocity(D3DXVECTOR3 inputVelocity)
{
	m_Velocity = inputVelocity;
}

void CData_Attack::setTime(float inputTime)
{
	m_fTime = inputTime;
}
