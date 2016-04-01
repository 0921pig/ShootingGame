#pragma once

class CScene;

class CStage : public CScene
{
public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

	virtual void LoadTexture();
	virtual void CreateBaseObjects();

public:
	CStage(SceneNo WhatStage);
	virtual ~CStage();
};

