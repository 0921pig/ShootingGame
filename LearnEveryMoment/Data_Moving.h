#pragma once
#include "stdafx.h"

class CData_Moving
{
private:
	// Move에 있어 중요한 것은 데이터는
	// 어느 시간에, 어느 위치에 있느냐.
	// 그렇다면 도착 시간과 도착 위치를 저장하면 된다.
	float m_DurationTime;
	D3DXVECTOR3 m_DestPos;

public:
	const float getTime() { return m_DurationTime; }
	const D3DXVECTOR3 getPos_Dest() { return m_DestPos; }

	void setTime(float inputTime);
	void setPos_Dest(D3DXVECTOR3 inputVec);

public:
	CData_Moving();
	CData_Moving(D3DXVECTOR3 DestPos, float DurationTime);
	~CData_Moving();
};

