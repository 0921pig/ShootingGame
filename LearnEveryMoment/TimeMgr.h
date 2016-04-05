#pragma once
#include "Base.h"

class CTimeMgr
{
public:
	DECLARE_SINGLETON(CTimeMgr);

public:
	LARGE_INTEGER			m_CurrentTime;
	LARGE_INTEGER			m_prevTime;
	LARGE_INTEGER			m_CpuTick;

	float					m_fTime;
public:
	void InitTimeMgr();
	void SetTime();
	float GetTime() { return m_fTime; }

private:
	CTimeMgr();
public:
	~CTimeMgr();
};

