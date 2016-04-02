#pragma once
#include "Base.h"

class CTexture;
class CTextureMgr
{
public:
	DECLARE_SINGLETON(CTextureMgr);
private:
	map<const TCHAR*, CTexture*>	m_MapTexture;
public:
	const TEXINFO* GetTexture(const TCHAR* pObjKey, const TCHAR* pStatKey = NULL,
		const int& iCnt = 0);
public:
	HRESULT	InsertTexture(const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeID,
		const TCHAR* pStatKey = NULL, const int& iCnt = 0);
	void Release();
private:
	CTextureMgr();
public:
	virtual ~CTextureMgr();
};

