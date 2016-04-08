#pragma once

class CScene;
class CPlayerControl;
class CBack_Stage;

class CStage : public CScene
{
private:
	CBack_Stage* m_background;
	CPlayerControl* m_PlayerControl;
	
	bool isClear_ThisStage;

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

