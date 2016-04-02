#pragma once
#include "Base.h"

class CTexture
{
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStatKey = NULL, const int& iCnt = 0)PURE;
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStatKey = NULL, const int& iCnt = 0)PURE;
	virtual void Release()PURE;
public:
	CTexture();
	virtual ~CTexture();
};

