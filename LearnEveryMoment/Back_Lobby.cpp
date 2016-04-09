#include "stdafx.h"
#include "Include.h"
#include <math.h>

CBack_Lobby::CBack_Lobby()
	:isMoving_NumberBack(false)
{
	m_NumberBack.position_current = -171.f;
}

CBack_Lobby::~CBack_Lobby()
{
}

void CBack_Lobby::Initialize()
{
	setSortID(SortID_Back);

	setObjKey(L"Background");
	setObjName(L"Lobby");

	setTextrueKey(L"Main");
	setStateKey(L"Normal");

	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	getObjInfo()->setMatWorld(matScale * matTrans);
}

void CBack_Lobby::Progress()
{
	if (isMoving_NumberBack == true)
	{
		m_NumberBack.distance_forStop = (float)(0.5 * m_NumberBack.speed_cur * (m_NumberBack.speed_cur / (m_NumberBack.acceleration * GET_SINGLE(CTimeMgr)->GetTime()))); //정지거리
		m_NumberBack.distance_toGoal = m_NumberBack.position_goal - m_NumberBack.position_current; // 남은거리
	
		if (m_NumberBack.distance_toGoal > 0.f)
		{
			// 오른쪽 방향
			if (m_NumberBack.distance_forStop < m_NumberBack.distance_toGoal)
			{
				// 가속
				m_NumberBack.speed_cur += m_NumberBack.acceleration * GET_SINGLE(CTimeMgr)->GetTime();
				if (m_NumberBack.speed_cur > m_NumberBack.speed_max)
					m_NumberBack.speed_cur = m_NumberBack.speed_max;
			}
			else
			{
				// 감속
				m_NumberBack.speed_cur -= m_NumberBack.acceleration * GET_SINGLE(CTimeMgr)->GetTime() * abs(m_NumberBack.distance_forStop / m_NumberBack.distance_toGoal);
				if (m_NumberBack.speed_cur < 0.f)
				{
					m_NumberBack.speed_cur = 0.f;
				}
			}
		}
		else if(m_NumberBack.distance_toGoal < 0.f)
		{
			//왼쪽방향
			if (-m_NumberBack.distance_forStop > m_NumberBack.distance_toGoal)
			{
				// 가속
				m_NumberBack.speed_cur -= m_NumberBack.acceleration * GET_SINGLE(CTimeMgr)->GetTime();
				if (m_NumberBack.speed_cur < -m_NumberBack.speed_max)
					m_NumberBack.speed_cur = -m_NumberBack.speed_max;
			}
			else
			{
				// 감속
				m_NumberBack.speed_cur += (m_NumberBack.acceleration) * GET_SINGLE(CTimeMgr)->GetTime() * abs(m_NumberBack.distance_forStop / m_NumberBack.distance_toGoal);
				if (m_NumberBack.speed_cur > 0.f)
				{
					m_NumberBack.speed_cur = 0.f;
				}
			}
		}

		// 현재속도로 실제로 이동하기
		m_NumberBack.position_current += m_NumberBack.speed_cur;

		if (abs(m_NumberBack.position_current - m_NumberBack.position_goal) < 1.f)
		{
			// 도착지점에 도착했을 때 강력하게 멈추기
			m_NumberBack.speed_cur = 0.f;
			m_NumberBack.position_current = m_NumberBack.position_goal;
			isMoving_NumberBack = false;

		}
	}

	// NumberBack Position_Info
	calculateMatworld(&m_NumberBackInfo, D3DXVECTOR3(-m_NumberBack.position_current, 0.f, 0.f));
}

void CBack_Lobby::Render()
{
	drawTexture(getObjInfo(), RefPos_LeftTop, 0, getObjkey(), getObjName(), getTexturekey(), getStatekey());
	drawTexture(&m_NumberBackInfo, RefPos_LeftTop, 0, getObjkey(), getObjName(), L"Number", getStatekey(), 255);
}

void CBack_Lobby::Release()
{
}

CObj * CBack_Lobby::Clone()
{
	return new CBack_Lobby(*this);
}

void CBack_Lobby::moveNumberBack(AircraftTypeOfPlayer inputAircraft)
{
	float startPos = -171.f; 
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(getObjkey(), getObjName(), L"Number", getStatekey(), 0);
	float endPos = pTexInfo->ImgInfo.Width - WINSIZEX + 165.f;

	float distance_between = (endPos - startPos) / 4.f;

	m_NumberBack.acceleration = 20.f;
	m_NumberBack.speed_max = 10.f;

	switch (inputAircraft)
	{
	case AT_SuperHornet:
		m_NumberBack.position_goal = startPos;
		break;
	case AT_Stealth:
		m_NumberBack.position_goal = startPos + distance_between;
		break;
	case AT_Raptor:
		m_NumberBack.position_goal = startPos + distance_between * 2;
		break;
	case AT_Harrier:
		m_NumberBack.position_goal = startPos + distance_between * 3;
		break;
	case AT_Phantom:
		m_NumberBack.position_goal = endPos;
		break;
	}

	isMoving_NumberBack = true;
}
