#pragma once
#include "stdafx.h"

class CData_Move
{
private:
	// Move�� �־� �߿��� ���� �����ʹ�
	// ��� �ð���, ��� ��ġ�� �ִ���.
	// �׷��ٸ� ���� �ð��� ���� ��ġ�� �����ϸ� �ȴ�.
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

