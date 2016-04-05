#include "stdafx.h"
#include "TimeMgr.h"


CTimeMgr::CTimeMgr()
{
}


CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::InitTimeMgr()
{
	QueryPerformanceCounter(&m_CurrentTime);
	QueryPerformanceCounter(&m_prevTime);
	QueryPerformanceFrequency(&m_CpuTick);
}

void CTimeMgr::SetTime()
{
	QueryPerformanceCounter(&m_CurrentTime);

	m_fTime = float(m_CurrentTime.QuadPart - m_prevTime.QuadPart) / m_CpuTick.QuadPart;
	m_prevTime = m_CurrentTime;
}

float CTimeMgr::GetTime()
{
	return 0.01f;
	//return m_fTime;
}
