#pragma once
#include "Scene.h"
class CLobby : public CScene
{
private:
	CLobbyObjProto m_Proto;

public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

	virtual void LoadTexture();
public:
	CLobby();
	virtual ~CLobby();
};

