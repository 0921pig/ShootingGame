#pragma once
#include "stdafx.h"

class CProtoType // ���� ������ �������̽�. 
{
public:
	virtual HRESULT InitProtoInstance()PURE;
	virtual void Release()PURE;
public:
	CProtoType();
	virtual ~CProtoType();
};

