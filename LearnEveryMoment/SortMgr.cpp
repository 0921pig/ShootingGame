#include "stdafx.h"
#include "SortMgr.h"
#include "Include.h"

CSortMgr::CSortMgr()
{
	for (int i = 0; i < SortID_MaxSize; ++i)
	{
		m_ObjList[i].clear();
	}
}

CSortMgr::~CSortMgr()
{
}

void CSortMgr::AddSortObject(CObj* pObj)
{
	SortID ID = pObj->getSortID();

	m_ObjList[ID].push_back(pObj);
}

void CSortMgr::RenderObject(void)
{
	for (int i = 0; i < SortID_MaxSize; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin();
		iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render();
		}
		m_ObjList[i].clear();
	}
}
