#include "SingleTexture.h"
#include "Include.h"

CSingleTexture::CSingleTexture()
{
}


CSingleTexture::~CSingleTexture()
{
	Release();
}

const TEXINFO* CSingleTexture::GetTexture(const TCHAR* pStatKey /*= NULL*/, const int& iCnt /*= 0*/)
{
	return m_pTexInfo;
}

HRESULT CSingleTexture::InsertTexture(const TCHAR* pFileName, const TCHAR* pStatKey /*= NULL*/, const int& iCnt /*= 0*/)
{
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO));

	if (FAILED(D3DXGetImageInfoFromFile(pFileName, &m_pTexInfo->ImgInfo)))
		return E_FAIL;

	// ',' 컴마가 변수 바로 앞에 있는것이 더 보기에 편하다. 특히 컴마 쓰는걸 빼먹은경우 
	if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDeviceMgr)->GetDevice()
		, pFileName, m_pTexInfo->ImgInfo.Width
		, m_pTexInfo->ImgInfo.Height, m_pTexInfo->ImgInfo.MipLevels
		, 0, m_pTexInfo->ImgInfo.Format
		, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT
		, D3DCOLOR_ARGB(255, 255, 255, 255)
		, &m_pTexInfo->ImgInfo
		, NULL, &m_pTexInfo->pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CSingleTexture::Release()
{
	if (m_pTexInfo)
	{
		m_pTexInfo->pTexture->Release();
		delete m_pTexInfo;
		m_pTexInfo = NULL;
	}
}
