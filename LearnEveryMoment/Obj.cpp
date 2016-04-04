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



void CObj::calculateMatworld(CInfo_Obj * pInfo, D3DXVECTOR3 inputPos, D3DXVECTOR3 inputScale)
{
	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	pInfo->setPos(inputPos);
	D3DXMatrixTranslation(&matTrans, pInfo->getPos().x, pInfo->getPos().y, pInfo->getPos().z);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, inputScale.x, inputScale.y, inputScale.z);

	pInfo->setMatWorld(matScale * matTrans);
}

void CObj::drawTexture(CInfo_Obj* inputInfo, RefPos option_RF, int iCnt, const TCHAR * in_pObjType, const TCHAR * in_pObjName, const TCHAR * in_pTextureName, const TCHAR * in_pStateKey,
	int opacity, D3DXVECTOR3 Position)
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(in_pObjType, in_pObjName, in_pTextureName, in_pStateKey, iCnt);
	if (pTexInfo == NULL)
	{
		TRACE(L"GetTexture 실패 (%s %s %s %s)\n", in_pObjType, in_pObjName, in_pTextureName, in_pStateKey);
		return;
	}

	GET_SINGLE(CDeviceMgr)->GetSprite()->SetTransform(&inputInfo->getMatWorld());
	

	if (opacity > 255 || opacity < 0)	{ //투명도 범위 체크
		ERR_MSG(g_hWnd, L"Opacity 수치 확인 바람. 0 <= opacity <= 255 를 반드시 충족해야 함.");
		return;
	}
		

	switch (option_RF)
	{
	case RefPos_LeftTop:
		GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &Position, NULL, D3DCOLOR_ARGB(opacity, 255, 255, 255));
		break;
	
	case RefPos_Center:
		inputInfo->setCenter(D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f, pTexInfo->ImgInfo.Height / 2.f, 0.f));
		GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &inputInfo->getCenter(), &Position, D3DCOLOR_ARGB(opacity, 255, 255, 255));
		break;
	}
}

void CObj::setTextrueKey(TCHAR * inputKey)
{
	m_pTextureKey = inputKey;
}
