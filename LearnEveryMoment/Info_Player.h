#pragma once
#include "Include.h"

class CInfo_Player
{
private:
	PlayableAircraft m_aircraftName;
	int m_score;
	int m_countBomb;
	int m_levelWeapon;

private:
	void setAircraftName(PlayableAircraft aircraft);

public:
	PlayableAircraft getAircraftName();

	void initialize(PlayableAircraft aircraft);

	void increaseBomb();
	void decreaseBomb();

	void increaseWeaponLevel();
	void decreaseWeaponLevel();

	void increaseScore(int point);
	void decreaseScore(int point);


public:
	CInfo_Player();
	~CInfo_Player();
};

