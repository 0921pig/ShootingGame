#pragma once


class CPlayer_Belonging
{
private:
	AircraftTypeOfPlayer m_aircraftType;
	int m_score;
	int m_NumOfBomb;
	int m_LevelOfWeapon;

private:
	void setAircraftType(AircraftTypeOfPlayer aircraft);

public:
	AircraftTypeOfPlayer getAircraftType();
	void initialize(AircraftTypeOfPlayer aircraft);

	void increase_NumOfBomb();
	void decrease_NumOfBomb();

	void increase_LevelOfWeapon();
	void decrease_LevelOfWeapon();

	void increase_Score(int point);
	void decrease_Score(int point);


public:
	CPlayer_Belonging();
	~CPlayer_Belonging();
};

