#pragma once
#include "stdafx.h"
#include "ObjMgr.h"
#include "ObjProto.h"
#include "Include.h"

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

CObj* CObjMgr::AddObject(CProtoType* pProto, const TCHAR* pObjType, D3DXVECTOR3 vPos)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObjType);

	CObj*  pProtoInst = ((CObjProto*)pProto)->GetProto(pObjType);
	if (pProtoInst == NULL)
	{
		TRACE(L"ObjMgr에서 %s 생성 중에 에러 발생\n", pObjType);
		ERR_MSG(g_hWnd, L"ObjMgr AddObject 에러");
		return NULL;
	}

	CObj* pObject = pProtoInst->Clone();
	pObject->setPosition(vPos); // 좌표 대입
	pObject->Initialize();

	if (iter == m_MapObject.end())
	{
		//pObjType 리스트가 없으면, 새로 리스트를 만듦.
		list<CObj*> Objlist;
		Objlist.push_back(pObject);

		m_MapObject.insert(make_pair(pObjType, Objlist));
	}
	else
	{
		//pObjType 리스트가 있다면 거기에 추가.
		iter->second.push_back(pObject);
	}

	return pObject;
}

CObj* CObjMgr::AddEnemyObject(CProtoType* pProto, const TCHAR* pObjType, D3DXVECTOR3 vPos, MovingPattern_Type MovingType, AttackPattern_Type AttackType)
{
	CEnemyAircraft* pEnemyObj = (CEnemyAircraft*)AddObject(pProto, pObjType, vPos);
	
	CMovingPattern* pMovingPattern = GET_SINGLE(CPatternMgr)->GetMovingPattern(MovingType);
	CAttackPattern* pAttackPattern = GET_SINGLE(CPatternMgr)->GetAttackPattern(AttackType);

	pEnemyObj->applyPattern(pMovingPattern, pAttackPattern);

	return (CObj*)pEnemyObj;
}

void CObjMgr::Progress()
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{
			/* Progress */
			(*list_iter)->Progress();

			GET_SINGLE(CSortMgr)->AddSortObject(*list_iter);
		}
	}


}

void CObjMgr::Render()
{
	GET_SINGLE(CSortMgr)->RenderObject();
}

void CObjMgr::Release()
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin(); iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{
			SAFE_DELETE(*list_iter);
		}
		iter->second.clear();
	}
	m_MapObject.clear();
}

HRESULT CObjMgr::DeleteObject(CObj* pObj)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObj->getObjkey());

	if (iter == m_MapObject.end())
	{
		//pObjType 리스트가 없으면, 종료. 이지만 그럴리가 있나
		ERR_MSG(g_hWnd, L"이게 가능한 경우냐 ? Delete Object");
	}
	else
	{
		delete pObj;
		iter->second.remove(pObj);
	}

	return S_OK;
}
