#include "stdafx.h"
#include "Info_Obj.h"
#include "Include.h"

CObj::CObj()
	:m_pObjType(NULL), m_pObjName(NULL), m_pTextureKey(NULL), m_pStateKey(NULL), m_SortID(SortID_None)
{
}


CObj::~CObj()
{
}

void CObj::setSortID(SortID inputSortID)
{
	m_SortID = inputSortID;
}

void CObj::setObjKey(TCHAR * inputKey)
{
	m_pObjType = inputKey;
}

void CObj::setObjName(TCHAR * inputName)
{
	m_pObjName = inputName;
}

void CObj::setStateKey(TCHAR * inputStateKey)
{
	m_pStateKey = inputStateKey;
}

void CObj::setPosition(D3DXVECTOR3 inputPos)
{
	m_Info.setPos(inputPos);
}

void CObj::drawTexture(CInfo_Obj* inputInfo, RefPos option_RF, int iCnt, const TCHAR * in_pObjType, const TCHAR * in_pObjName, const TCHAR * in_pTextureName, const TCHAR * in_pStateKey)
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(in_pObjType, in_pObjName, in_pTextureName, in_pStateKey, iCnt);
	if (pTexInfo == NULL)
	{
		TRACE(L"GetTexture ���� (%s %s %s %s)\n", in_pObjType, in_pObjName, in_pTextureName, in_pStateKey);
		return;
	}

	GET_SINGLE(CDeviceMgr)->GetSprite()->SetTransform(&inputInfo->getMatWorld());
	

	switch (option_RF)
	{
	case RefPos_LeftTop:
		GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexture, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	
	case RefPos_Center:
		inputInfo->setCenter(D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f, pTexInfo->ImgInfo.Height / 2.f, 0.f));
		GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &inputInfo->getCenter(), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	}
}

void CObj::setTextrueKey(TCHAR * inputKey)
{
	m_pTextureKey = inputKey;
}
