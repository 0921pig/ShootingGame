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
	void AddSchedule(int topPoint, D3DXVECTOR3 startPosition, TCHAR* objectName, MovingPattern_Type MovingType, AttackPattern_Type AttackType);
	void schedulingProcess();

public:
	CObjScheduleMgr();
	~CObjScheduleMgr();
};

typedef struct Row_ObjectSchedule
{
	int m_TopPoint;
	D3DXVECTOR3 m_StartPosition;
	TCHAR* m_ObjectName;
	MovingPattern_Type m_MovingType;
	AttackPattern_Type m_AttackType;

	Row_ObjectSchedule()
		:m_TopPoint(0), m_StartPosition(0.f, 0.f, 0.f), m_ObjectName(NULL), m_MovingType(MovingType_None), m_AttackType(AttackType_None)
	{
	}

	Row_ObjectSchedule(int _topPoint, D3DXVECTOR3 _startPosition, TCHAR* _ObjectName, MovingPattern_Type _MovingType, AttackPattern_Type _AttackType)
		:m_TopPoint(_topPoint), m_StartPosition(_startPosition), m_ObjectName(_ObjectName), m_MovingType(_MovingType), m_AttackType(_AttackType)
	{
	}

	~Row_ObjectSchedule()
	{
	}
}Row_ObjectSchedule;