#include "stdafx.h"
#include "Aircraft.h"

CAircraft::CAircraft()
{
}

CAircraft::~CAircraft()
{
}



float CAircraft::getSpeed()
{
	return m_Speed;
}

void CAircraft::setSpeed(float inputSpeed)
{
	m_Speed = inputSpeed;
}
