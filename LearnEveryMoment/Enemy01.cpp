#include "stdafx.h"
#include "Include.h"

CEnemy01::CEnemy01()
{
}

CEnemy01::~CEnemy01()
{
	Release();
}

void CEnemy01::Initialize()
{
	setSortID(SortID_Enemy);

	setObjKey(L"Aircraft");
	setObjName(L"Enemy01");

	setTextrueKey(L"Body");
	setStateKey(L"Normal");
}

void CEnemy01::Progress()
{
	calculateMatworld(getObjInfo(), getObjInfo()->getPos(), D3DXVECTOR3(0.2f, -0.2f, 0.f));
}

void CEnemy01::Render()
{
	drawTexture(getObjInfo(), RefPos_Center, 0, getObjkey(), getObjName(), getTexturekey(), getStatekey());
}

void CEnemy01::Release()
{

}

CObj* CEnemy01::Clone()
{
	return new CEnemy01(*this);
}

