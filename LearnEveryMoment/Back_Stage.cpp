#include "stdafx.h"
#include "Include.h"

CBack_Stage::CBack_Stage()
	:m_TopPointOfTheMap(0)
{
}

CBack_Stage::~CBack_Stage()
{
}

void CBack_Stage::Initialize()
{
	setSortID(SortID_Back);

	setObjKey(L"Background");
	setObjName(L"Stage_01");

	setTextrueKey(L"Main");
	setStateKey(L"Normal");

	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	getObjInfo()->setMatWorld(matScale * matTrans);

	m_TopPointOfTheMap = getHeightOfTheMap() - WINSIZEY;
}

void CBack_Stage::Progress()
{
}

void CBack_Stage::Render()
{
	drawTexture(getObjInfo(), RefPos_LeftTop, 0, getObjkey(), getObjName(), getTexturekey(), getStatekey(), 255);
}

void CBack_Stage::Release()
{
}

CObj* CBack_Stage::Clone()
{
	return new CBack_Stage(*this);
}

int CBack_Stage::getHeightOfTheMap()
{
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(getObjkey(), getObjName(), getTexturekey(), getStatekey(), 0);
	if (pTexInfo == NULL)
	{
		TRACE(L"TexInfo 로드 에러 발생 (CBack_Stage getMapHeight() - %s %s %s %s\n", getObjkey(), getObjName(), getTexturekey(), getStatekey());
		return 0;
	}

	return (int)(pTexInfo->ImgInfo.Height);
}

