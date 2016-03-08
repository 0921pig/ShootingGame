#pragma once
#include "Scene.h"

class CStage : public CScene
{
public:
	virtual HRESULT Initialize();
	virtual SceneCode Progress();
	virtual void KeyCheck();
	virtual void Render();
	virtual void Release();

public:
	CStage();
	virtual ~CStage();
};

