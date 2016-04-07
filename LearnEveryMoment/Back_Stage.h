#pragma once
#include "Obj.h"

class CBack_Stage :	public CObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	CBack_Stage();
	virtual ~CBack_Stage();
};

