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
	CObj* AddObject(CProtoType* pProto, const TCHAR* pObjType, D3DXVECTOR3 vPos = D3DXVECTOR3(0.f, 0.f, 0.f));
	HRESULT DeleteObject(CObj* pObj);
	
	void Progress();
	void Render();
	void Release();

private:
	CObjMgr();
public:
	~CObjMgr();
};

