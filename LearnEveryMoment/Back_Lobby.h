#pragma once

#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

#include "Obj.h"

class CBack_Lobby :	public CObj
{
private:

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();


public:
	CBack_Lobby();
	virtual ~CBack_Lobby();
};

