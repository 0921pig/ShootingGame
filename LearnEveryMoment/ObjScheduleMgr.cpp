#include "stdafx.h"
#include "Include.h"
#include "ObjScheduleMgr.h"

CObjScheduleMgr::CObjScheduleMgr()
{
}


CObjScheduleMgr::~CObjScheduleMgr()
{
}

void CObjScheduleMgr::Initialize(const int* pTopPoint, CProtoType* pProto)
{
	m_StageProto = pProto;
	m_pTopPointOfTheMap = pTopPoint;
}

void CObjScheduleMgr::AddSchedule(int _topPoint, D3DXVECTOR3 _startPosition, TCHAR* _objectName)
{
	m_SchedulingList.push_back(Row_ObjectSchedule(_topPoint, _startPosition, _objectName));
}

void CObjScheduleMgr::schedulingProcess(int _topPoint)
{
	/* 스케쥴 포인트에 도착했거나 지나친 것이 있으면 Object를 생성하는 함수 */

	while (m_SchedulingList.size() > 0 && m_SchedulingList.front().topPoint <= *m_pTopPointOfTheMap)
	{
		Row_ObjectSchedule input = m_SchedulingList.front();
		GET_SINGLE(CObjMgr)->AddObject(m_StageProto, input.ObjectName, input.startPosition);
		m_SchedulingList.pop_front();
	}
}
