#pragma once
#include "Obj.h"
#include "ProtoType.h"

class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	map<const TCHAR*, list<CObj*>> m_MapObject;
	list<CObj*>	m_DeleteList;

public:
	HRESULT AddObject(CProtoType* pProto, const TCHAR* pObjType);
	HRESULT DeleteObject(CObj* pObj);
	
	void Progress();
	void Render();
	void Release();

private:
	CObjMgr();
public:
	~CObjMgr();
};

