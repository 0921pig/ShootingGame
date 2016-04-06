#include "stdafx.h"
#include "Info_Player.h"

CInfo_Player::CInfo_Player()
	:m_aircraftName(PA_None), m_score(0), m_countBomb(0), m_levelWeapon(0)
{
}


CInfo_Player::~CInfo_Player()
{
}

PlayableAircraft CInfo_Player::getAircraftName()
{
	return m_aircraftName;
}

void CInfo_Player::setAircraftName(PlayableAircraft aircraft)
{
	m_aircraftName = aircraft;
}

void CInfo_Player::initialize(PlayableAircraft aircraft)
{
	if (aircraft == PA_None)
	{
		ERR_MSG(g_hWnd, L"에러 발생");
		TRACE(L"CInfo_Player initialize(PA_None) 발생. 매개변수로 PA_None이 오면 안됨. 체크바람");
		return;
	}
	
	setAircraftName(aircraft);

	m_countBomb = 2;
	m_levelWeapon = 1;
}

void CInfo_Player::increaseBomb()
{
	++m_countBomb;

	if (m_countBomb > 3)
		m_countBomb = 3;
}

void CInfo_Player::decreaseBomb()
{
	--m_countBomb;

	if (m_countBomb < 0)
		m_countBomb = 0;
}

void CInfo_Player::increaseWeaponLevel()
{
	++m_levelWeapon;

	if (m_levelWeapon > 4) //최대 레벨이 3인지 4인지 5인지 기억나지 않는다. 최대 레벨 찾아보기. 집에서..
		m_levelWeapon = 4;
}

void CInfo_Player::decreaseWeaponLevel()
{
	--m_levelWeapon;

	if (m_levelWeapon < 1)
		m_levelWeapon = 1;
}

void CInfo_Player::increaseScore(int point)
{
	m_score += point;
}

void CInfo_Player::decreaseScore(int point)
{
	m_score -= point;
}
