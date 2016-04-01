#pragma once

#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

class CObj;

class CBackground :	public CObj
{
private:
	SceneNo m_SceneNo;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();


public:
	CBackground(SceneNo SceneNum);
	~CBackground();
};

