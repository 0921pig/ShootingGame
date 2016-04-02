#pragma once
#include "Texture.h"

class CMultiTexture : public CTexture
	//Multi Texture란? 하나의 캐릭터가 여러장의 이미지를 가진 경우 ex) 아칸 
{
private:
	map<const TCHAR*, vector<TEXINFO*>> m_MapTexture;
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStatKey = NULL, const int& iCnt = 0);
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStatKey = NULL, const int& iCnt = 0);
	virtual void Release();
public:
	CMultiTexture();
	~CMultiTexture();
};

