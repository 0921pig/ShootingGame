#pragma once
#include "Base.h"

class CTexture;
class CTextureMgr
{
public:
	DECLARE_SINGLETON(CTextureMgr);

private:
	map<const TCHAR*, map<const TCHAR*, map<const TCHAR*, CTexture*>>>  m_MapTexture;

public:
	const TEXINFO* GetTexture(const TCHAR* pObjType, const TCHAR* pObjName, const TCHAR* pTextureName, const TCHAR* pStateKey = L"Normal", 
		const int& iCnt = 0);

public:
	HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pObjType, const TCHAR* pObjName, const TCHAR* pTextureName,
		const TCHAR* pStateKey = L"Normal", const int& iCnt = 0);
	void Release();

public:
	CTextureMgr(void);
	~CTextureMgr(void);
};

