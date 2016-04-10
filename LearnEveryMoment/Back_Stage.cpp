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
	setStateKey(L"Small");

	m_TopPointOfTheMap = WINSIZEY - 2;
}

void CBack_Stage::Progress()
{
	m_TopPointOfTheMap += 10;

	for (int i = 0; i < 10; ++i)
	{
		float temp = (float)((getTopPointOfTheMap() - 1 ) % 100) + i * 100.f - 100.f;
		calculateMatworld(&m_MapStrips[i], D3DXVECTOR3(0.f, temp, 0.f));
	}
}

void CBack_Stage::Render()
{
	for (int i = 0; i < 10; ++i)
	{
		int temp = (int)((getHeightOfTheMap() - getTopPointOfTheMap() - getHeightOfTheMap()%100) / 100 + (i));
		drawTexture(&m_MapStrips[i], RefPos_LeftTop, temp, getObjkey(), getObjName(), getTexturekey(), getStatekey(), 255);
	}
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
	//const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(getObjkey(), getObjName(), getTexturekey(), getStatekey(), 0);
	//if (pTexInfo == NULL)
	//{
	//	TRACE(L"TexInfo 로드 에러 발생 (CBack_Stage getMapHeight() - %s %s %s %s\n", getObjkey(), getObjName(), getTexturekey(), getStatekey());
	//	return 0;
	//}

	//return (int)(pTexInfo->ImgInfo.Height);

	return 18165;
}

int CBack_Stage::getTopPointOfTheMap()
{
	return m_TopPointOfTheMap;
}

void CBack_Stage::setTopPointOfTheMap(int TopPoint)
{
	m_TopPointOfTheMap = TopPoint;
}

