#include "ObjMgr.h"
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

	if (pProtoInst == NULL)
		return E_FAIL;

	CObj* pObject = pProtoInst->Clone();
	pObject->Initialize();

	if (iter == m_MapObject.end())
	{
		//pObjKey 리스트가 없으면, 새로 리스트를 만들고 객체를 추가하면 되고 
		list<CObj*> Objlist;
		Objlist.push_back(pObject);

		m_MapObject.insert(make_pair(pObjKey, Objlist));
	}
	else
	{
		//pObjKey 리스트가 있다면 이미 만들어져 있는 리스트에 객체를 추가한다.
		iter->second.push_back(pObject);
	}

	if (pObject->GetSortID() == SORTID_GROUND_OBJECT)
		GET_SINGLE(CPush)->AddObject(pObject);

	return S_OK;
}

HRESULT CObjMgr::AddObject(CProtoType* pProto, const TCHAR* pObjKey, D3DXVECTOR3 vPos)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObjKey);

	CObj*  pProtoInst = ((CObjProto*)pProto)->GetProto(pObjKey);

	if (pProtoInst == NULL)
		return E_FAIL;

	CObj* pObject = pProtoInst->Clone();
	pObject->Initialize();

	pObject->SetInfovPos(vPos);

	if (iter == m_MapObject.end())
	{
		//pObjKey 리스트가 없으면, 새로 리스트를 만들고 객체를 추가하면 되고 
		list<CObj*> Objlist;
		Objlist.push_back(pObject);

		m_MapObject.insert(make_pair(pObjKey, Objlist));
	}
	else
	{
		//pObjKey 리스트가 있다면 이미 만들어져 있는 리스트에 객체를 추가한다.
		iter->second.push_back(pObject);
	}

	if (pObject->GetSortID() == SORTID_GROUND_OBJECT)
	{
		if (pObject->GetObjType() != OBJ_TYPE_StageStatic)
			GET_SINGLE(CPush)->AddObject(pObject);
	}

	return S_OK;
}


SCENE CObjMgr::Progress()
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{
			/* Progress 사전 처리 */





			/* Progress */
			SCENE SceneID = (*list_iter)->Progress();

			if (SceneID >= 0)
				return SceneID;

			/* Progress 사후 처리 */


			// 소멸되었는지 아닌지 확인하는 방법을 알아내야

			/* 렌더링 작업에 투입 */
			GET_SINGLE(CSortMgr)->AddSortObject(*list_iter);

		}
	}

	return SCENE_NONPASS;
}

void CObjMgr::Render()
{
	GET_SINGLE(CSortMgr)->RenderObject();
}

void CObjMgr::Release()
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
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

const vector<TILE*>* CObjMgr::GetTileInfo()
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(L"StageBack");

	if (iter == m_MapObject.end())
	{
		ERR_MSG(g_hWnd, L"타일정보를 가지고 있는 객체가 없습니다.");
		return NULL;
	}

	return ((CStageBack*)(iter->second.front()))->GetTileInfo();
}

const D3DXVECTOR3* CObjMgr::GetScrollInfo()
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(L"StageBack");

	if (iter == m_MapObject.end())
	{
		ERR_MSG(g_hWnd, L"스크롤정보없음");
		return NULL;
	}

	return ((CStageBack*)(iter->second.front()))->GetScrollInfo();
}

const OBJINFO* CObjMgr::GetInfo(const TCHAR* pObjKey, const int& iCnt /*= 0*/)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObjKey);

	if (iter == m_MapObject.end())
		return NULL;


	list<CObj*>::iterator iter1 = iter->second.begin();

	for (int i = 0; i < iCnt; ++i)
		++iter1;

	return (*iter1)->GetInfo();
}

CObj* CObjMgr::WhoAreYou()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	OBJINFO Info;
	ZeroMemory(&Info, sizeof(Info));

	Info.vPos = D3DXVECTOR3(float(ptMouse.x) + GET_SINGLE(CObjMgr)->GetScrollInfo()->x
		, float(ptMouse.y + GET_SINGLE(CObjMgr)->GetScrollInfo()->y), 0.f);


	/* 위치로 object 찾기 */

	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		if ((iter->second.begin()) == (iter->second.end()))
			continue;

		if ((*iter).second.front()->GetSortID() != SORTID_GROUND_OBJECT)
		{
			continue;
		}

		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{

			D3DXVECTOR3 vDir = (*list_iter)->GetInfo()->vPos - Info.vPos;
			float fLength = D3DXVec3Length(&vDir);

			if (fLength < (*list_iter)->GetInfo()->radius)
				return *list_iter;
		}
	}

	return NULL;
}

CObj* CObjMgr::WhoAreYou(D3DXVECTOR3 vPoint)
{
	OBJINFO Info;
	ZeroMemory(&Info, sizeof(Info));

	Info.vPos = D3DXVECTOR3(vPoint.x, vPoint.y, 0.f);

	/* 위치로 object 찾기 */
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		if ((iter->second.begin()) == (iter->second.end()))
			continue;

		if ((*iter).second.front()->GetSortID() != SORTID_GROUND_OBJECT)
		{
			continue;
		}

		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{

			D3DXVECTOR3 vDir = (*list_iter)->GetInfo()->vPos - Info.vPos;
			float fLength = D3DXVec3Length(&vDir);

			if (fLength < (*list_iter)->GetInfo()->radius)
				return *list_iter;
		}
	}

	return NULL;
}

void CObjMgr::AddObject_Drag(RECT rect)
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		if ((iter->second.begin()) == (iter->second.end()))
			continue;

		if ((*(iter->second.begin()))->GetSortID() != SORTID_GROUND_OBJECT)
			continue;

		if ((*(iter->second.begin()))->GetObjType() == OBJ_TYPE_DynamicBuilding)
			continue;

		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{
			D3DXVECTOR3 vPos = (*list_iter)->GetInfo()->vPos;
			if (vPos.x > rect.left && vPos.x < rect.right && vPos.y > rect.top && vPos.y < rect.bottom)
				GET_SINGLE(CSelectMgr)->AddObject(*list_iter);
		}
	}

	// 아무것도 없으면 건물추가
	if (GET_SINGLE(CSelectMgr)->GetSelect_Size() == 0)
	{
		for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
		iter != m_MapObject.end(); ++iter)
		{
			// #수정 이부분 해결해야 속도가 빨라질듯
			//	if ( (*iter).second->front()->GetSortID() != NULL) //->second->front() )
			//->GetSortID() != SORTID_GROUND_OBJECT)
			//	continue;

			if ((iter->second.begin()) == (iter->second.end()))
				continue;

			if ((*(iter->second.begin()))->GetSortID() != SORTID_GROUND_OBJECT)
				continue;

			if ((*(iter->second.begin()))->GetObjType() != OBJ_TYPE_DynamicBuilding)
				continue;

			for (list<CObj*>::iterator list_iter = iter->second.begin();
			list_iter != iter->second.end(); ++list_iter)
			{
				D3DXVECTOR3 vPos = (*list_iter)->GetInfo()->vPos;
				if (vPos.x > rect.left && vPos.x < rect.right && vPos.y > rect.top && vPos.y < rect.bottom)
				{
					GET_SINGLE(CSelectMgr)->AddObject(*list_iter);
					return;
				}
			}
		}
	}
}

void CObjMgr::PUSH_AddAllObject()
{
	for (map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.begin();
	iter != m_MapObject.end(); ++iter)
	{
		if ((iter->second.begin()) == (iter->second.end()))
			continue;

		if ((*(iter->second.begin()))->GetSortID() != SORTID_GROUND_OBJECT)
			continue;

		for (list<CObj*>::iterator list_iter = iter->second.begin();
		list_iter != iter->second.end(); ++list_iter)
		{
			GET_SINGLE(CPush)->AddObject(*list_iter);
		}
	}
}

void CObjMgr::Delete_ObjInList()
{
	for (list<CObj*> ::iterator iter = m_DeleteList.begin(); iter != m_DeleteList.end(); ++iter)
	{
		DeleteObject((*iter));
	}

	m_DeleteList.clear();
}

void CObjMgr::SetScrollInfo(D3DXVECTOR3 vScroll)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(L"StageBack");

	if (iter == m_MapObject.end())
	{
		ERR_MSG(g_hWnd, L"스크롤정보없음");
		return;
	}

	((CStageBack*)(iter->second.front()))->SetScrollInfo(vScroll);
}

HRESULT CObjMgr::DeleteObject(CObj* pObj)
{
	map<const TCHAR*, list<CObj*>>::iterator iter = m_MapObject.find(pObj->getObjkey());

	if (iter == m_MapObject.end())
	{
		//pObjKey 리스트가 없으면, 종료. 이지만 그럴리가 있나
		ERR_MSG(g_hWnd, L"이게 가능한 경우냐 ? Delete Object");
	}
	else
	{
		delete pObj;
		iter->second.remove(pObj);
	}

	return S_OK;
}

void CObjMgr::Add_DeleteList(CObj* pObj)
{
	m_DeleteList.push_back(pObj);
}

void CObjMgr::AddObject_DoubleClick(CObj* pObj)
{
	map<const TCHAR*, list<CObj*>>::iterator Map_iter = m_MapObject.find(pObj->getObjkey());

	if (Map_iter == m_MapObject.end())
		return;
	else
	{
		list<CObj*> ::iterator iter;
		for (iter = Map_iter->second.begin(); iter != Map_iter->second.end(); ++iter)
		{
			if (isInScreen(*iter) == true)
			{
				GET_SINGLE(CSelectMgr)->AddObject(*iter);
			}
		}
	}


}

bool CObjMgr::isInScreen(CObj* pObj)
{
	D3DXVECTOR3 vPos = pObj->GetInfo()->vPos;


	if (vPos.x > GET_SINGLE(CObjMgr)->GetScrollInfo()->x + 0.f
		&& vPos.x < GET_SINGLE(CObjMgr)->GetScrollInfo()->x + WINSIZEX
		&& vPos.y > GET_SINGLE(CObjMgr)->GetScrollInfo()->y + 0.f
		&& vPos.y < GET_SINGLE(CObjMgr)->GetScrollInfo()->y + WINSIZEY)
		return true;

	return false;
}
