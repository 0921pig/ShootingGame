#include "stdafx.h"
#include "ObjProto.h"
#include "Include.h"

CObjProto::CObjProto()
{
}

CObjProto::~CObjProto()
{
	Release();
}



CObj* CObjProto::GetProto(const TCHAR* pObjType)
{
	map<const TCHAR*, CObj*>::iterator iter = m_MapProto.find(pObjType);

	if (iter == m_MapProto.end())
	{
		// 내용이 텅 비어 있을 경우는 NULL리턴
		ERR_MSG(g_hWnd, L"복사하려는 ProtoType 객체가 없습니다.");
		return NULL;
	}
	else
	{
		// 내용이 비어 있지 않는 경우에는 덩어리 리턴
		return iter->second;
	}
}

void CObjProto::Release()
{
	map<const TCHAR*, CObj*>::iterator iter;

	for (iter = m_MapProto.begin();	iter != m_MapProto.end(); ++iter)
	{
		SAFE_DELETE(iter->second);
	}

	m_MapProto.clear();
}

