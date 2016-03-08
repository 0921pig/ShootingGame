#pragma once
#include "stdafx.h"

enum SceneReturn;

class CScene
{
public:
	virtual void Initialize()PURE;
	virtual SceneReturn Progress()PURE;
	virtual void KeyCheck()PURE;
	virtual void Render()PURE;
	virtual void Release();

public:
	CScene();
	virtual ~CScene();
};

enum SceneReturn
{
	SceneReturn_None,
	SceneReturn_NextStage,
	SceneReturn_GameOver
};
