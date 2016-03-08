#pragma once
#include "Scene.h"

class CStage : public CScene
{
public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyCheck();
	virtual void Render();
	virtual void Release();

public:
	CStage();
	virtual ~CStage();
};

