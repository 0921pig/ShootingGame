#pragma once
#include "stdafx.h"
#include "Data_Moving.h"

class CMovingPattern
{
private:
	list<CData_Moving> m_MovingList;

public:
	CMovingPattern();
	~CMovingPattern();
};

