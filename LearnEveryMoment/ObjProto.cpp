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
		// ������ �� ��� ���� ���� NULL����
		ERR_MSG(g_hWnd, L"�����Ϸ��� ProtoType ��ü�� �����ϴ�.");
		return NULL;
	}
	else
	{
		// ������ ��� ���� �ʴ� ��쿡�� ��� ����
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

