#include "stdafx.h"
#include "Include.h"

CPlayer_Belonging::CPlayer_Belonging()
	:m_aircraftType(AT_None), m_score(0), m_NumOfBomb(0), m_LevelOfWeapon(0)
{
}


CPlayer_Belonging::~CPlayer_Belonging()
{
}

AircraftTypeOfPlayer CPlayer_Belonging::getAircraftType()
{
	return m_aircraftType;
}

void CPlayer_Belonging::setAircraftType(AircraftTypeOfPlayer aircraft)
{
	m_aircraftType = aircraft;
}

void CPlayer_Belonging::initialize(AircraftTypeOfPlayer aircraft)
{
	if (aircraft == AT_None)
	{
		ERR_MSG(g_hWnd, L"에러 발생");
		TRACE(L"CPlayer_Belonging initialize(AT_None) 발생. 매개변수로 AT_None이 오면 안됨. 체크바람");
		return;
	}
	
	setAircraftType(aircraft);

	m_NumOfBomb = 2;
	m_LevelOfWeapon = 1;
}

void CPlayer_Belonging::increase_NumOfBomb()
{
	++m_NumOfBomb;

	if (m_NumOfBomb > 3)
		m_NumOfBomb = 3;
}

void CPlayer_Belonging::decrease_NumOfBomb()
{
	--m_NumOfBomb;

	if (m_NumOfBomb < 0)
		m_NumOfBomb = 0;
}

void CPlayer_Belonging::increase_LevelOfWeapon()
{
	++m_LevelOfWeapon;

	if (m_LevelOfWeapon > 4) //최대 레벨이 3인지 4인지 5인지 기억나지 않는다. 최대 레벨 찾아보기. 집에서..
		m_LevelOfWeapon = 4;
}

void CPlayer_Belonging::decrease_LevelOfWeapon()
{
	--m_LevelOfWeapon;

	if (m_LevelOfWeapon < 1)
		m_LevelOfWeapon = 1;
}

void CPlayer_Belonging::increase_Score(int point)
{
	m_score += point;
}

void CPlayer_Belonging::decrease_Score(int point)
{
	m_score -= point;
}
