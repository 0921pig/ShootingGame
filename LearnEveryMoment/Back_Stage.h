#pragma once
#include "Obj.h"
#include "Info_Obj.h"

class CBack_Stage :	public CObj
{
private:
	int m_TopPointOfTheMap;

	CInfo_Obj	m_MapStrips[10];
	int			m_NumOfMapStrip[10];

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	int getHeightOfTheMap();
	const int* getTopPointPointer();
	int getTopPointOfTheMap();
	void setTopPointOfTheMap(int TopPoint);

public:
	CBack_Stage();
	virtual ~CBack_Stage();
};

