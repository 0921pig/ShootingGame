#pragma once
#include "stdafx.h"
#include "Base.h"

class CProtoType // 얘의 역할은 인터페이스. 
{
public:
	virtual HRESULT InitProtoInstance()PURE;
	virtual void Release()PURE;
public:
	CProtoType();
	virtual ~CProtoType();
};

