#pragma once
#include "stdafx.h"
#include "Data_Moving.h"

class CMovingPattern
{
private:
	list<CData_Moving> m_MovingList;
	
public:
	void convert_RelativeToAbsolute(D3DXVECTOR3 startPos);
	void add_MovingSchedule(D3DXVECTOR3 DestPos_Relative, float durationTime); // 다양한 위치에 활용하게 위해 상대좌표로 이동한다

public:
	CMovingPattern();
	~CMovingPattern();
};

