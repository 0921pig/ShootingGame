#pragma once
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

HRESULT CObjMgr::AddObject(CProtoType* pProto, const TCHAR* pObjKey)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObjKey);

	CObj*  pProtoInst = ((CObjProto*)pProto)->GetProto(pObjKey);
	if (pProtoInst == NULL)	return E_FAIL;

	CObj* pObject = pProtoInst->Clone();
	pObject->Initialize();

	if (iter == m_MapObject.end())
	{
		//pObjKey ����Ʈ�� ������, ���� ����Ʈ�� ����.
		list<CObj*> Objlist;
		Objlist.push_back(pObject);

		m_MapObject.insert(make_pair(pObjKey, Objlist));
	}
	else
	{
		//pObjKey ����Ʈ�� �ִٸ� �ű⿡ �߰�.
		iter->second.push_back(pObject);
	}

	return S_OK;
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
		}
	}
}

void CObjMgr::Render()
{
	//GET_SINGLE(CSortMgr)->RenderObject();
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
		//pObjKey ����Ʈ�� ������, ����. ������ �׷����� �ֳ�
		ERR_MSG(g_hWnd, L"�̰� ������ ���� ? Delete Object");
	}
	else
	{
		delete pObj;
		iter->second.remove(pObj);
	}

	return S_OK;
}
