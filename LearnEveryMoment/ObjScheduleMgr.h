#pragma once
#include "Include.h"

typedef struct Row_ObjectSchedule Row_ObjectSchedule;

/* 
Object Schedule Mgr의 역할은 간단한다.
특정 위치에 도착했을 때, 미리 스케쥴링 된 오브젝트를 생성한다.
끝.
*/

class CObjScheduleMgr
{
	DECLARE_SINGLETON(CObjScheduleMgr);

private:
	const int* m_pTopPointOfTheMap;
	list<Row_ObjectSchedule> m_SchedulingList;
	CProtoType* m_StageProto;

public:
	void Initialize(const int* pTopPoint, CProtoType* pProto);
	void AddSchedule(int topPoint, D3DXVECTOR3 startPosition, TCHAR* objectName);
	void schedulingProcess();

public:
	CObjScheduleMgr();
	~CObjScheduleMgr();
};

typedef struct Row_ObjectSchedule
{
	int topPoint;
	D3DXVECTOR3 startPosition;
	TCHAR* ObjectName;

	Row_ObjectSchedule()
		:topPoint(0), startPosition(0.f, 0.f, 0.f), ObjectName(NULL)
	{
	}

	Row_ObjectSchedule(int _topPoint, D3DXVECTOR3 _startPosition, TCHAR* _ObjectName)
		:topPoint(_topPoint), startPosition(_startPosition), ObjectName(_ObjectName)
	{
	}

	~Row_ObjectSchedule()
	{
	}

}Row_ObjectSchedule;