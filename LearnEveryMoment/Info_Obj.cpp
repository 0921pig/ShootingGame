#include "Info_Obj.h"

CInfo_Obj::CInfo_Obj()
	:vPos(0.f, 0.f, 0.f), vDir(1.f, 0.f, 0.f), radius(0)
{
}


CInfo_Obj::~CInfo_Obj()
{
}

void CInfo_Obj::setPos(D3DXVECTOR3 inputPos)
{
	vPos = inputPos;
}

void CInfo_Obj::setDir(D3DXVECTOR3 inputDir)
{
	vDir = inputDir;
}

void CInfo_Obj::setMatWorld(D3DXMATRIX inputMatWorld)
{
	matWorld = inputMatWorld;
}

void CInfo_Obj::setRadius(float inputRadius)
{
	radius = inputRadius;
}

