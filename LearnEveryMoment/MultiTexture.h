#pragma once
#include "Texture.h"

class CMultiTexture : public CTexture
	//Multi Texture��? �ϳ��� ĳ���Ͱ� �������� �̹����� ���� ��� ex) ��ĭ 
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

