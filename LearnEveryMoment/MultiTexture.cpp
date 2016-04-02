#include "stdafx.h"
#include "MultiTexture.h"
#include "DeviceMgr.h"

CMultiTexture::CMultiTexture(void)
{
}


CMultiTexture::~CMultiTexture(void)
{
	Release();
}

HRESULT CMultiTexture::InsertTexture( const TCHAR* pFileName, const TCHAR* pStateKey, const int& iCnt )
{

	TCHAR   szPath[128] = L"";

	vector<TEXINFO*> vecTexture;
	//vecTexture.reserve(iCnt); //공간 미리 확보

	for(int i =0; i< iCnt; ++i)
	{
		wsprintf(szPath, pFileName, i);

		TEXINFO* pTexInfo = new TEXINFO();
		ZeroMemory(pTexInfo,sizeof(TEXINFO));

		if(FAILED(D3DXGetImageInfoFromFile(L"resource/image/Daniel.jpg",&pTexInfo->ImgInfo)))
			return E_FAIL;

		if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDeviceMgr)->GetDevice()
			, L"resource/image/Daniel.jpg", pTexInfo->ImgInfo.Width
			, pTexInfo->ImgInfo.Height, pTexInfo->ImgInfo.MipLevels
			, 0, pTexInfo->ImgInfo.Format
			, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT
			, D3DCOLOR_ARGB(255, 0, 0, 0)
			, &pTexInfo->ImgInfo
			, NULL, &pTexInfo->pTexture)))
			return NULL;


		vecTexture.push_back(pTexInfo);
	}

	m_MapTexture.insert(make_pair(pStateKey,vecTexture));


	return S_OK;
}

const TEXINFO* CMultiTexture::GetTexture(const TCHAR* pStateKey, const int& iCnt )
{
	map<const TCHAR*,vector<TEXINFO*>>::iterator iter = m_MapTexture.find(pStateKey);

	if(iter == m_MapTexture.end())
		return NULL;

	//TEXINFO* pTexInfo = iter->second[0];

	//if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDeviceMgr)->GetDevice()
	//	, L"resource/image/back_Lobby.png", pTexInfo->ImgInfo.Width
	//	, pTexInfo->ImgInfo.Height, pTexInfo->ImgInfo.MipLevels
	//	, 0, pTexInfo->ImgInfo.Format
	//	, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT
	//	, D3DCOLOR_ARGB(255, 0, 0, 0)
	//	, &pTexInfo->ImgInfo
	//	, NULL, &pTexInfo->pTexture)))
	//	return NULL;

	return iter->second[iCnt];
}

void CMultiTexture::Release()
{
	for(map<const TCHAR*,vector<TEXINFO*>>::iterator iter = m_MapTexture.begin();
		iter != m_MapTexture.end();++iter)
	{
		for(unsigned int i =0; i< iter->second.size();++i)
		{
			iter->second[i]->pTexture->Release();
			delete iter->second[i];
			iter->second[i] = NULL;
		}
		iter->second.clear();
	}
	m_MapTexture.clear();


}
