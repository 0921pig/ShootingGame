#pragma once
#include "Obj.h"m,
#include "ProtoType.h"

class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	map<const TCHAR*, list<CObj*>> m_MapObject;
	list<CObj*>	m_DeleteList;

	//�� list�ΰɱ�, �Ƹ� �ڷ������ �����ϱ� ����. Ball�� Ball���. Back�� Back���
public:
	const vector<TILE*>* GetTileInfo();
	const D3DXVECTOR3* GetScrollInfo();
	void SetScrollInfo(D3DXVECTOR3 vScroll);
	const OBJINFO* GetInfo(const TCHAR* pObjKey, const int& iCnt = 0);
	CObj* WhoAreYou();
	CObj* WhoAreYou(D3DXVECTOR3 vPoint);
	void AddObject_Drag(RECT rect);
	void AddObject_DoubleClick(CObj* pObj);
	void PUSH_AddAllObject();
	void Delete_ObjInList();

	bool isInScreen(CObj* pObj);

	//const�� �ѱ�� �ʹ�.
	map<const TCHAR*, list<CObj*>> GetObjectInfo() { return m_MapObject; }

public:
	HRESULT AddObject(CProtoType* pProto, const TCHAR* pObjKey);
	HRESULT AddObject(CProtoType* pProto, const TCHAR* pObjKey, D3DXVECTOR3 vPos);

	HRESULT DeleteObject(CObj* pObj);
	void Add_DeleteList(CObj* pObj);
	SCENE Progress();
	void Render();
	void Release();

private:
	CObjMgr();
public:
	~CObjMgr();
};

