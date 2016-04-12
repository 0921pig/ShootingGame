#include "stdafx.h"
#include "Include.h"

CHarrier::CHarrier()
{
}


CHarrier::~CHarrier()
{
	Release();
}

void CHarrier::Initialize()
{
	setSortID(SortID_Player);

	setObjKey(L"Aircraft");
	setObjName(L"Harrier");

	setTextrueKey(L"Body");
	setStateKey(L"Normal");

	calculateMatworld(getObjInfo(), D3DXVECTOR3(WINSIZEX/2.f, WINSIZEY - 100.f, 0.f), D3DXVECTOR3(2.7f, 2.7f, 0.f));

	setSpeed(5.f);
}


void CHarrier::Progress()
{
	calculateMatworld(getObjInfo(), getObjInfo()->getPos(), D3DXVECTOR3(2.7f, 2.7f, 0.f));
}

void CHarrier::Render()
{
	drawTexture(getObjInfo(), RefPos_Center, 3, getObjkey(), getObjName(), getTexturekey(), getStatekey());
}

void CHarrier::Release()
{

}

CObj* CHarrier::Clone()
{
	return new CHarrier(*this);
}

