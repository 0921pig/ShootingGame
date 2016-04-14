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

}

void CObjScheduleMgr::AddSchedule(int _topPoint, D3DXVECTOR3 _startPosition, TCHAR* _objectName)
{
	m_SchedulingList.push_back(Row_ObjectSchedule(_topPoint, _startPosition, _objectName));
}

void CObjScheduleMgr::schedulingProcess(int _topPoint)
{
	/* ������ ����Ʈ�� �����߰ų� ����ģ ���� ������ Object�� �����ϴ� �Լ� */
	while (m_SchedulingList.front().topPoint <= *m_pTopPointOfTheMap) 
	{
		Row_ObjectSchedule input = m_SchedulingList.front();
		GET_SINGLE(CObjMgr)->AddObject(m_StageProto, input.ObjectName, input.startPosition);
		m_SchedulingList.pop_front();
	}
}
