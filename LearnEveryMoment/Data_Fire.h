#pragma once
#include "stdafx.h"

class CData_Fire
{
private:
	// Fire���� �߿��� ���� �����ϱ�?
	// ����(time), ���� ��������� �Ŀ���(v, a)
	D3DXVECTOR3 m_Accel;
	D3DXVECTOR3 m_Velocity;
	float m_fTime;

public:
	D3DXVECTOR3 getAccel() { return m_Accel; }
	D3DXVECTOR3 getVelocity() { return m_Velocity; }
	float getTime() { return m_fTime; }

	void setAccel(D3DXVECTOR3 inputAccel);
	void setVelocity(D3DXVECTOR3 inputVelocity);
	void setTime(float inputTime);

public:
	CData_Fire();
	~CData_Fire();
};

