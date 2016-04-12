#include "stdafx.h"
#include "Include.h"

CPlayerControl::CPlayerControl(AircraftTypeOfPlayer Name)
	:m_Belonging(NULL)
{
	switch (Name)
	{
	case AT_Harrier:
		break;
	case AT_Phantom:
		break;
	case AT_Raptor:
		break;
	case AT_Stealth:
		break;
	case AT_SuperHornet:
		break;
	}
}

CPlayerControl::~CPlayerControl()
{
}

void CPlayerControl::Initialize()
{

}

void CPlayerControl::Progress()
{

}

void CPlayerControl::Render()
{

}

void CPlayerControl::Release()
{

}

CObj* CPlayerControl::Clone()
{
	return new CPlayerControl(*this);
}

void CPlayerControl::setBelonging(CPlayer_Belonging* inputBelonging)
{
	m_Belonging = inputBelonging;
}

void CPlayerControl::setAircraft(CAircraft* inputAircraft)
{
	m_Aircraft = inputAircraft;
}

CAircraft* CPlayerControl::getAircraft()
{
	return m_Aircraft;
}
