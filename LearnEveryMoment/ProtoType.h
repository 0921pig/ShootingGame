#pragma once
#include "stdafx.h"
#include "Base.h"

class CProtoType // ���� ������ �������̽�. 
{
public:
	virtual HRESULT InitProtoInstance()PURE;
	virtual void Release()PURE;
public:
	CProtoType();
	virtual ~CProtoType();
};

