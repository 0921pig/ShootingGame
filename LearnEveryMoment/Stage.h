#pragma once
#include "Scene.h"

class CStage : public CScene
{
public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

	virtual void LoadTexture();

public:
	CStage(SceneNo WhatStage);
	virtual ~CStage();
};

