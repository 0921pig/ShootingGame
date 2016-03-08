#pragma once
#include "stdafx.h"

enum SceneCode;

class CScene
{
public:
	virtual HRESULT Initialize()PURE;
	virtual SceneCode Progress()PURE;
	virtual void KeyCheck()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CScene();
	virtual ~CScene();
};

enum SceneCode
{
	SceneCode_None,
	SceneCode_NextStage,
	SceneCode_GameOver
};
