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
	// ���⼭ ��� �̹��� Load
	// ����� Texture Manager�� ����ؼ� �̹����� Texture�� ����ϸ� ��.
	
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
	// ���⼭ ��� ������� ����
}

void CBackground::Render()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture( getObjkey(), getStatekey(), 0 ); // iCnt�� ��� �ذ��ؾ�����
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
