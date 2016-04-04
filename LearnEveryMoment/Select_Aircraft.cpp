#include "stdafx.h"
#include "Include.h"

CSelect_Aircraft::CSelect_Aircraft(PlayableAircraft aircraft)
	:isRandom(false)
	, m_Aircraft(aircraft)
{
}

CSelect_Aircraft::~CSelect_Aircraft()
{
	Release();
}

void CSelect_Aircraft::Initialize()
{
	setSortID(SortID_AirCraft);

	setObjKey(L"Aircraft");
	setTextrueKey(L"Body");
	setStateKey(L"Normal");

	switch (m_Aircraft)
	{
	case PA_Harrier:
		setObjName(L"Harrier");
		break;
	case PA_Stealth:
		setObjName(L"Stealth");
		break;
	case PA_Raptor:
		setObjName(L"Raptor");
		break;
	case PA_Phantom:
		setObjName(L"Phantom");
		break;
	case PA_SuperHornet:
		setObjName(L"SuperHornet");
		break;
	case PA_Random:
		isRandom = true;
		setObjName(L"Harrier");
		m_Aircraft = PA_Harrier;
		break;
	}
}

void CSelect_Aircraft::Progress()
{
	if (isRandom == true){
		change_AircraftName(m_Aircraft);
	}


	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, getObjInfo()->getPos().x, getObjInfo()->getPos().y, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, 3.f, 3.f, 0.f);

	getObjInfo()->setMatWorld(matScale * matTrans);
}

void CSelect_Aircraft::Render()
{
	drawTexture(getObjInfo(), RefPos_Center, 3, getObjkey(), getObjName(), getTexturekey(), getStatekey());
}

void CSelect_Aircraft::Release()
{
}

CObj * CSelect_Aircraft::Clone()
{
	return new CSelect_Aircraft(*this);
}

void CSelect_Aircraft::change_AircraftName(PlayableAircraft AircraftName)
{
	switch (AircraftName)
	{
	case PA_Harrier:
		m_Aircraft = PA_Stealth;
		setObjName(L"Stealth");
		break;
	case PA_Stealth:
		m_Aircraft = PA_Raptor;
		setObjName(L"Raptor");
		break;
	case PA_Raptor:
		m_Aircraft = PA_Phantom;
		setObjName(L"Phantom");
		break;
	case PA_Phantom:
		m_Aircraft = PA_SuperHornet;
		setObjName(L"SuperHornet");
		break;
	case PA_SuperHornet:
		m_Aircraft = PA_Harrier;
		setObjName(L"Harrier");
		break;
	}
}
