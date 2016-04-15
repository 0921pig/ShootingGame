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
	setObjName(L"Stage01");

	setTextrueKey(L"Main");
	//setStateKey(L"");

	m_TopPointOfTheMap = WINSIZEY - 2;
}

void CBack_Stage::Progress()
{
	m_TopPointOfTheMap += 2;

	if (getTopPointOfTheMap() > getHeightOfTheMap())
		return;

	for (int i = 0; i < 10; ++i)
	{
		calculateMatworld(&m_MapStrips[i], D3DXVECTOR3(0.f, (float)((getTopPointOfTheMap() + 1) % 100 - 100) + i * 100.f, 0.f));
		m_NumOfMapStrip[i] = ((getHeightOfTheMap() - WINSIZEY) / 100) - ((getTopPointOfTheMap() + 1 - WINSIZEY) / 100) + i - 1;
	}

		
}

void CBack_Stage::Render()
{
	for (int i = 0; i < 10; ++i)
	{
		drawTexture(&m_MapStrips[i], RefPos_LeftTop, m_NumOfMapStrip[i], getObjkey(), getObjName(), getTexturekey(), L"Small", 255);
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
	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(getObjkey(), getObjName(), getTexturekey(), L"Big", 0);
	if (pTexInfo == NULL)
	{
		TRACE(L"TexInfo 로드 에러 발생 (CBack_Stage getMapHeight() - %s %s %s %s\n", getObjkey(), getObjName(), getTexturekey(), L"Big");
		return 0;
	}

	return (int)(pTexInfo->ImgInfo.Height);
}

const int* CBack_Stage::getTopPointPointer()
{
	return &m_TopPointOfTheMap;
}

int CBack_Stage::getTopPointOfTheMap()
{
	return m_TopPointOfTheMap;
}

void CBack_Stage::setTopPointOfTheMap(int TopPoint)
{
	m_TopPointOfTheMap = TopPoint;
}

