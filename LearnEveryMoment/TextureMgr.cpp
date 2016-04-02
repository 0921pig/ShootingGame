#include "TextureMgr.h"
#include "Include.h"

CTextureMgr::CTextureMgr()
{
}


CTextureMgr::~CTextureMgr()
{
	Release();
}

const TEXINFO* CTextureMgr::GetTexture(const TCHAR* pObjKey, const TCHAR* pStatKey /*= NULL*/, const int& iCnt /*= 0*/)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	if (iter == m_MapTexture.end())
		return NULL;

	return iter->second->GetTexture(pStatKey, iCnt);
}

HRESULT CTextureMgr::InsertTexture(const TCHAR* pFileName, const TCHAR* pObjKey, TEXTYPE TypeID,
	const TCHAR* pStatKey /*= NULL*/, const int& iCnt /*= 0*/)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	CTexture*	pTexture = NULL;

	switch (TypeID)
	{
	case TEXTYPE_SINGLE:
		if (iter == m_MapTexture.end())
			pTexture = new CSingleTexture;
		else
			return E_FAIL;
		break;
	case TEXTYPE_MULTI:
		if (iter == m_MapTexture.end())
			pTexture = new CMultiTexture;
		else
			pTexture = pTexture = (*iter).second;

		break;
	}

	if (FAILED(pTexture->InsertTexture(pFileName, pStatKey, iCnt)))
		return E_FAIL;

	m_MapTexture.insert(make_pair(pObjKey, pTexture));

	return S_OK;
}


void CTextureMgr::Release()
{
	for (map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.begin();
		iter != m_MapTexture.end(); ++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}

	m_MapTexture.clear();
}
