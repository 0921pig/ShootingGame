#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "Include.h"


CTextureMgr::CTextureMgr(void)
{
}


CTextureMgr::~CTextureMgr(void)
{
}

const TEXINFO * CTextureMgr::GetTexture(const TCHAR * pObjType, const TCHAR * pObjName, const TCHAR * pTextureName, const TCHAR * pStateKey, const int & iCnt)
{
	// 1단계
	map<const TCHAR*, map<const TCHAR*, map<const TCHAR*, CTexture*>>>::iterator iter_ObjType = m_MapTexture.find(pObjType);
	if (iter_ObjType == m_MapTexture.end())
		return NULL;
	
	// 2단계
	map<const TCHAR*, map<const TCHAR*, CTexture* >>::iterator iter_ObjName = iter_ObjType->second.find(pObjName);
	if (iter_ObjName == iter_ObjType->second.end())
		return NULL;

	// 3단계
	map<const TCHAR*, CTexture* > ::iterator iter_TextureName = iter_ObjName->second.find(pObjName);
	if (iter_TextureName == iter_ObjName->second.end())
		return NULL;
	
	return iter_TextureName->second->GetTexture(pStateKey, iCnt);
}

HRESULT CTextureMgr::InsertTexture(const TCHAR * pFileName, const TCHAR * pObjType, const TCHAR * pObjName, const TCHAR * pTextureName, const TCHAR * pStateKey, const int & iCnt)
{
	// 1단계
	map<const TCHAR*, map<const TCHAR*, map<const TCHAR*, CTexture*>>>::iterator iter_ObjType = m_MapTexture.find(pObjType);
	if (iter_ObjType == m_MapTexture.end())	{
		// 해당하는 노드가 없으면 추가한다.
		m_MapTexture.insert(make_pair(pObjType, map<const TCHAR*, map<const TCHAR*, CTexture*>>()));
		iter_ObjType = m_MapTexture.find(pObjType);
	}
	
	// 2단계
	map<const TCHAR*, map<const TCHAR*, CTexture*>>::iterator iter_ObjName = iter_ObjType->second.find(pObjName);
	if (iter_ObjName == iter_ObjType->second.end()) {
		// 해당하는 노드가 없으면 추가한다.
		iter_ObjType->second.insert(make_pair(pObjName, map<const TCHAR*, CTexture*>()));
		iter_ObjName = iter_ObjType->second.find(pObjType);
	}

	// 3단계
	map<const TCHAR*, CTexture*>::iterator iter_TextureName = iter_ObjName->second.find(pTextureName);
	if (iter_TextureName == iter_ObjName->second.end()) {
		// 해당하는 노드가 없으면 추가한다.
		CTexture* pTexture = new CMultiTexture;
		iter_ObjName->second.insert(make_pair(pTextureName, pTexture));
		iter_TextureName = iter_ObjName->second.find(pTextureName);
	}

	if (FAILED(iter_TextureName->second->InsertTexture(pFileName, pStateKey, iCnt)))
		return E_FAIL;
		
	return S_OK;
}

void CTextureMgr::Release()
{
	for(map<const TCHAR*, map<const TCHAR*, map<const TCHAR*, CTexture*>>>::iterator iter_ObjType = m_MapTexture.begin(); 
		iter_ObjType != m_MapTexture.end(); ++iter_ObjType)
	{
		for (map<const TCHAR*, map<const TCHAR*, CTexture*>>::iterator iter_ObjName = iter_ObjType->second.begin();
		iter_ObjName != iter_ObjType->second.end(); ++iter_ObjName)
		{
			for (map<const TCHAR*, CTexture*>::iterator iter_TextureName = iter_ObjName->second.begin();
			iter_TextureName != iter_ObjName->second.end(); ++iter_TextureName)
			{
				delete iter_TextureName->second;
				iter_TextureName->second = NULL;
			}
			iter_ObjName->second.clear();
		}
		iter_ObjType->second.clear();
	}
	m_MapTexture.clear();
}
