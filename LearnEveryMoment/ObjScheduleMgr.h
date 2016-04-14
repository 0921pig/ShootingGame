#pragma once
#include "Include.h"

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

class CObjScheduleMgr
{
	DECLARE_SINGLETON(CObjScheduleMgr);

private:
	const int* m_pTopPointOfTheMap;
	list<Row_ObjectSchedule> m_SchedulingList;
	CProtoType* m_StageProto;

public:
	void Initialize(const int* pTopPoint, CProtoType* pProto);
	void AddSchedule(int _topPoint, D3DXVECTOR3 _startPosition, TCHAR* _objectName);
	void schedulingProcess(int _topPoint);

public:
	CObjScheduleMgr();
	~CObjScheduleMgr();
};

