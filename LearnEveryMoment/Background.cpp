#include "stdafx.h"
#include "Include.h"


CBackground::CBackground(SceneNo SceneNum)
	: m_SceneNo(SceneNum)
{
	Initialize();
}

CBackground::~CBackground()
{
}

void CBackground::Initialize()
{
	// 여기서 배경 이미지 Load
	// 방법은 Texture Manager를 등록해서 이미지를 Texture로 등록하면 됨.
	
	setSortID(SortID_Back);

	setObjKey(L"Background");

	switch (m_SceneNo)
	{
	case SceneNo_None: break;
	case SceneNo_Lobby: setObjName(L"Lobby"); break;
	case SceneNo_Stage1: setObjName(L"State_01");  break;
	}

	setTextrueKey(L"Main");
	setStateKey(L"Normal");

	getObjInfo()->setPos(D3DXVECTOR3(100.f, 100.f, 100.f));
}

void CBackground::Progress()
{
	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, WINSIZEX/2.f, WINSIZEY/2.f, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	getObjInfo()->setMatWorld(matScale * matTrans);
}

void CBackground::Render()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture( getObjkey(), getObjName(), getTexturekey(), getStatekey(), 0); // iCnt를 어떻게 해결해야하지
	if (pTexInfo == NULL) 
		return;
	
	D3DXMATRIX temp = getObjInfo()->getMatWorld();
	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexInfo->ImgInfo.Width / 2.f, pTexInfo->ImgInfo.Height / 2.f, 0.f);
	
	GET_SINGLE(CDeviceMgr)->GetSprite()->SetTransform(&temp);
	GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexture, NULL, &vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CBackground::Release()
{
}

CObj * CBackground::Clone()
{
	return new CBackground(*this);
}
