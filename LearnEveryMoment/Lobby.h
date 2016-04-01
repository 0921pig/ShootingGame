#pragma once
#include "Scene.h"
class CLobby : public CScene
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
	CLobby();
	virtual ~CLobby();
};

