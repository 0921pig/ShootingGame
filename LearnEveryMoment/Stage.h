#pragma once

class CScene;
class CInfo_Player;

class CStage : public CScene
{
private:
	CInfo_Player* m_Player;

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

