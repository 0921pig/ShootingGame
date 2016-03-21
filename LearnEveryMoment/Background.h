#pragma once
#include "Base.h"
#include "Include.h"
#include "Obj.h"
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

