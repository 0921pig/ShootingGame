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
public:
	CLobby();
	virtual ~CLobby();
};

