#include "stdafx.h"
#include "Background.h"
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

	setTextrueKey(L"Background_Image");
	setStateKey(L"Normal");
}

void CBackground::Progress()
{
	// 여기서 어디를 출력할지 세팅
}

void CBackground::Render()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture( getObjkey(), getStatekey(), 0 ); // iCnt를 어떻게 해결해야하지
	if (pTexInfo == NULL) return;
	
	GET_SINGLE(CDeviceMgr)->GetSprite()->SetTransform(&(getObjInfo()->getMatWorld()));
	GET_SINGLE(CDeviceMgr)->GetSprite()->Draw(pTexInfo->pTexure, NULL, &( getObjInfo()->getCenter() ), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CBackground::Release()
{
}

CObj * CBackground::Clone()
{
	return new CBackground(*this);
}
