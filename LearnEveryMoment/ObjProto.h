#pragma once
#include "ProtoType.h"
#include "Include.h"

class CObjProto : public CProtoType
{
protected:
	map<const TCHAR*, CObj*>	m_MapProto;

public:
	CObj* GetProto(const TCHAR* pObjType);

public:
	virtual HRESULT InitProtoInstance()PURE;
	virtual void Release();
public:
	CObjProto();
	virtual ~CObjProto();
};

