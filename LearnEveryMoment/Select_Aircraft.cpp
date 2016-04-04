#include "stdafx.h"
#include "Include.h"

CSelect_Aircraft::CSelect_Aircraft(PlayableAircraft aircraft)
	:isRandom(false)
	, m_Aircraft(aircraft)
	, isSelected(false)
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
		isSelected = true;
		setObjName(L"SuperHornet");
		break;
	case PA_Random:
		isRandom = true;
		setObjName(L"Harrier");
		m_Aircraft = PA_Harrier;
		break;
	}

	//Big picture
	calculateMatworld(&m_BigPicture, D3DXVECTOR3(400.f, 320.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_WeaponInfo, D3DXVECTOR3(510.f, 456.f, 0.f), D3DXVECTOR3(3.6f, 2.7f, 0.f));
	calculateMatworld(&m_FighterCode, D3DXVECTOR3(026.f, 503.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_FighterNickname, D3DXVECTOR3(026.f, 576.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));

	//본체 Setting
	calculateMatworld(getObjInfo(), getObjInfo()->getPos(), D3DXVECTOR3(3.f, 3.f, 0.f));

	//커서 Setting
	calculateMatworld(&m_CursorSelecting, D3DXVECTOR3(getObjInfo()->getPos().x, 710.f, 0.f), D3DXVECTOR3(1.f, 1.f, 0.f));
}

void CSelect_Aircraft::Progress()
{
	if (isRandom == true){
		change_AircraftName(m_Aircraft);
	}



}

void CSelect_Aircraft::Render()
{


	drawTexture(getObjInfo(), RefPos_Center, 3, getObjkey(), getObjName(), getTexturekey(), getStatekey());
	//여기에 그림자 넣기

	
	if (isSelected == true) // Select 상태 일때 출력할 이미지
	{
		drawTexture(&m_CursorSelecting, RefPos_Center, 0, L"UI", L"Lobby", L"SelectMark", L"Normal");

		drawTexture(&m_BigPicture,		RefPos_Center,	0,	getObjkey(), getObjName(), L"Body",			L"Big");
		drawTexture(&m_WeaponInfo,		RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"WeaponInfo",	L"Normal");
		drawTexture(&m_FighterCode,		RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Code",			L"Normal");
		drawTexture(&m_FighterNickname, RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Nickname",		L"Normal");
	}
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
