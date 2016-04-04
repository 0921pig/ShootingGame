#include "stdafx.h"
#include "Include.h"


CBack_Lobby::CBack_Lobby()
{
}

CBack_Lobby::~CBack_Lobby()
{
}

void CBack_Lobby::Initialize()
{
	setSortID(SortID_Back);

	setObjKey(L"Background");
	setObjName(L"Lobby");

	setTextrueKey(L"Main");
	setStateKey(L"Normal");

	D3DXMATRIX	matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);

	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 0.f);

	getObjInfo()->setMatWorld(matScale * matTrans);
}

void CBack_Lobby::Progress()
{
	
}

void CBack_Lobby::Render()
{
	drawTexture(getObjInfo(), RefPos_LeftTop, 0, getObjkey(), getObjName(), getTexturekey(), getStatekey());
	drawTexture(getObjInfo(), RefPos_LeftTop, 0, getObjkey(), getObjName(), L"Number", getStatekey(), 255, D3DXVECTOR3(500.f, 0.f, 0.f));
}

void CBack_Lobby::Release()
{
}

CObj * CBack_Lobby::Clone()
{
	return new CBack_Lobby(*this);
}
