#pragma once
#include "stdafx.h"

class CInfo_Obj
{
private:
	D3DXVECTOR3	vPos; //좌상단 위치
	D3DXVECTOR3	vDir; //바라보고 있는 방향, 혹은 이동방향 처럼 방향벡터
	D3DXMATRIX	matWorld;
	float		radius;
public:
	D3DXVECTOR3 getPos() { return vPos; }
	D3DXVECTOR3 getDir() { return vDir; }
	D3DXMATRIX getMatWorld() { return matWorld; }
	float getRadius() { return radius; }

	void setPos(D3DXVECTOR3 inputPos);
	void setDir(D3DXVECTOR3 inputDir);
	void setMatWorld(D3DXMATRIX inputMatWorld);
	void setRadius(float inputRadius);



public:
	CInfo_Obj();
	~CInfo_Obj();
};

