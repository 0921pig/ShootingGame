#pragma once

class CScene;
class CInfo_Player;
class CPlayer_Aircraft;
class CBack_Stage;

class CStage : public CScene
{
private:
	CBack_Stage* m_background;
	CInfo_Player* m_Info_Player; // 같은 플레이어인데 두 곳에서 관리하는 것은 옳지않다. 통합해야한다. How. 어떤 방법이 물흐르듯 자연스러운 방법일까? 
	CPlayer_Aircraft* m_Player;
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

