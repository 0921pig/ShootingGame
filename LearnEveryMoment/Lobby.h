#pragma once
#include "Scene.h"
class CLobby : public CScene
{
public:
	virtual HRESULT Initialize();
	virtual SceneCode Progress();
	virtual void KeyCheck();
	virtual void Render();
	virtual void Release();
public:
	CLobby();
	virtual ~CLobby();
};

