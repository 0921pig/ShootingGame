#pragma once
#include "Base.h"
#include "Obj.h"

class CSortMgr
{
public:
	DECLARE_SINGLETON(CSortMgr);

private:
	list<CObj*>	m_ObjList[SortID_MaxSize];
public:
	void AddSortObject(CObj* pObj);
	void RenderObject(void);

private:
	CSortMgr();
public:
	~CSortMgr();
};

