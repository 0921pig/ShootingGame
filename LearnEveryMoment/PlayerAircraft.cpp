﻿#include "stdafx.h"
#include "Include.h"


CPlayerAircraft::CPlayerAircraft()
{
}


CPlayerAircraft::~CPlayerAircraft()
{
}

void CPlayerAircraft::MoveAircraft(DIR8 dir)
{
	D3DXVECTOR3 vDir;

	switch (dir)
	{
	case LEFTUP:
		vDir = D3DXVECTOR3(-1.f, -1.f, 0.f);
		break;
	case LEFT:
		vDir = D3DXVECTOR3(-1.f, 0.f, 0.f);
		break;
	case LEFTDOWN:
		vDir = D3DXVECTOR3(-1.f, +1.f, 0.f);
		break;
	case RIGHTUP:
		vDir = D3DXVECTOR3(+1.f, -1.f, 0.f);
		break;
	case RIGHT:
		vDir = D3DXVECTOR3(+1.f, 0.f, 0.f);
		break;
	case RIGHTDOWN:
		vDir = D3DXVECTOR3(+1.f, +1.f, 0.f);
		break;
	case UP:
		vDir = D3DXVECTOR3(0.f, -1.f, 0.f);
		break;
	case DOWN:
		vDir = D3DXVECTOR3(0.f, +1.f, 0.f);
		break;
	}

	vDir = vDir / D3DXVec3Length(&vDir); // Normalization

	D3DXVECTOR3 vPrevPos = getObjInfo()->getPos();
	getObjInfo()->setPos(vPrevPos + vDir * getSpeed());
}
