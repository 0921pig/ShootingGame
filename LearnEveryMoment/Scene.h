#pragma once
#include "stdafx.h"

enum SceneReturn;

class CScene
{
private:
	CProtoType* m_ProtoType;

public:
	virtual void LoadTexture()PURE;
	virtual void Initialize()PURE;
	virtual SceneReturn Progress()PURE;
	virtual void KeyProcess()PURE;
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
