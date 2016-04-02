#pragma once
#include "Texture.h"

class CSingleTexture : public CTexture
{
private:
	TEXINFO*		m_pTexInfo;
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStatKey = NULL, const int& iCnt = 0);
public:
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStatKey = NULL, const int& iCnt = 0);
	virtual void Release();
public:
	CSingleTexture();
	~CSingleTexture();
};

