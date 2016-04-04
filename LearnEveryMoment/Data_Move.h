#pragma once
#include "stdafx.h"

class CData_Move
{
private:
	// Move에 있어 중요한 것은 데이터는
	// 어느 시간에, 어느 위치에 있느냐.
	// 그렇다면 도착 시간과 도착 위치를 저장하면 된다.
	float m_fTime;
	D3DXVECTOR3 m_StartPos;
	D3DXVECTOR3 m_ArrivePos;

public:
	const float getTime() { return m_fTime; }
	const D3DXVECTOR3 getPos_Start() { return m_StartPos; }
	const D3DXVECTOR3 getPos_Arrive() { return m_ArrivePos; }

	void setTime(float inputTime);
	void setPos_Start(D3DXVECTOR3 inputVec);
	void setPos_Arrive(D3DXVECTOR3 inputVec);

public:
	CData_Move();
	~CData_Move();
};

