#include "stdafx.h"
#include "Include.h"

CSelect_Aircraft::CSelect_Aircraft(AircraftTypeOfPlayer aircraft)
	:isRandom(false)
	, m_Aircraft(aircraft)
	, isSelected(false)
{
}

void CSelect_Aircraft::select(bool val)
{
	isSelected = val;
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
	case AT_SuperHornet:
		setObjName(L"SuperHornet");
		break;
	case AT_Stealth:
		setObjName(L"Stealth");
		break;
	case AT_Raptor:
		setObjName(L"Raptor");
		break;
	case AT_Harrier:
		setObjName(L"Harrier");
		break;
	case AT_Phantom:
		setObjName(L"Phantom");
		break;
	case AT_Random:
		isRandom = true;
		setObjName(L"Harrier");
		m_Aircraft = AT_Harrier;
		break;
	}

	init_calculateMatrix();
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
		drawTexture(&m_CursorSelecting,			RefPos_Center, 0, L"UI", L"Lobby", L"SelectMark", L"Normal");

		drawTexture(&m_BigPicture,				RefPos_Center,	0,	getObjkey(), getObjName(), L"Body",			L"Big");
		drawTexture(&m_WeaponInfo,				RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"WeaponInfo",	L"Normal");
		drawTexture(&m_FighterCode_Shadow,		RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Code",			L"Shadow", 105);
		drawTexture(&m_FighterCode,				RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Code",			L"Normal");
		drawTexture(&m_FighterNickname_Shadow,	RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Nickname",		L"Shadow", 105);
		drawTexture(&m_FighterNickname,			RefPos_LeftTop, 0,	getObjkey(), getObjName(), L"Nickname",		L"Normal");
	}
}

void CSelect_Aircraft::Release()
{
}

CObj * CSelect_Aircraft::Clone()
{
	return new CSelect_Aircraft(*this);
}

void CSelect_Aircraft::change_AircraftName(AircraftTypeOfPlayer AircraftName)
{
	switch (AircraftName)
	{
	case AT_SuperHornet:
		m_Aircraft = AT_Stealth;
		setObjName(L"Stealth");
		break;
	case AT_Stealth:
		m_Aircraft = AT_Raptor;
		setObjName(L"Raptor");
		break;
	case AT_Raptor:
		m_Aircraft = AT_Harrier;
		setObjName(L"Harrier");
		break;
	case AT_Harrier:
		m_Aircraft = AT_Phantom;
		setObjName(L"Phantom");
		break;
	case AT_Phantom:
		m_Aircraft = AT_SuperHornet;
		setObjName(L"SuperHornet");
		break;
	}
}

void CSelect_Aircraft::init_calculateMatrix()
{
	//Big picture
	calculateMatworld(&m_BigPicture,				D3DXVECTOR3(400.f, 320.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_WeaponInfo,				D3DXVECTOR3(510.f, 440.f, 0.f), D3DXVECTOR3(3.6f, 2.5f, 0.f));
	calculateMatworld(&m_FighterCode,				D3DXVECTOR3(026.f, 503.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_FighterCode_Shadow,		D3DXVECTOR3(034.f, 510.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_FighterNickname,			D3DXVECTOR3(026.f, 576.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));
	calculateMatworld(&m_FighterNickname_Shadow,	D3DXVECTOR3(034.f, 583.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));


	//본체 Setting
	calculateMatworld(getObjInfo(), getObjInfo()->getPos(), D3DXVECTOR3(3.f, 3.f, 0.f));

	//커서 Setting
	calculateMatworld(&m_CursorSelecting, D3DXVECTOR3(getObjInfo()->getPos().x, 710.f, 0.f), D3DXVECTOR3(1.f, 1.f, 0.f));
}

