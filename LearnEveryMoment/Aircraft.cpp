#include "stdafx.h"
#include "Aircraft.h"

CAircraft::CAircraft()
{
}

CAircraft::~CAircraft()
{
}

void CAircraft::MoveAircraft(DIR4 dir)
{
	float speed = getSpeed();
	D3DXVECTOR3 prevPosition = getObjInfo()->getPos();

	switch(dir)
	{
	case DIR4_LEFT:
		getObjInfo()->setPos(D3DXVECTOR3(prevPosition.x - speed, prevPosition.y, prevPosition.z));
		break;
	case DIR4_UP:
		getObjInfo()->setPos(D3DXVECTOR3(prevPosition.x, prevPosition.y - speed, prevPosition.z));
		break;
	case DIR4_RIGHT:
		getObjInfo()->setPos(D3DXVECTOR3(prevPosition.x + speed, prevPosition.y, prevPosition.z));
		break;
	case DIR4_DOWN:
		getObjInfo()->setPos(D3DXVECTOR3(prevPosition.x, prevPosition.y + speed, prevPosition.z));
		break;
	}
}

float CAircraft::getSpeed()
{
	return m_Speed;
}

void CAircraft::setSpeed(float inputSpeed)
{
	m_Speed = inputSpeed;
}

