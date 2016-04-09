#pragma once
#include "Obj.h"
#include "Info_Obj.h"

class CBack_Stage :	public CObj
{
private:
	int m_TopPointOfTheMap;

	CInfo_Obj m_MapStrips[10];

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

private:
	int getHeightOfTheMap();
	int getTopPointOfTheMap();
	void setTopPointOfTheMap(int TopPoint);

public:
	CBack_Stage();
	virtual ~CBack_Stage();
};

