#pragma once

#ifndef HEADER_ManageScene
	#define HEADER_ManageScene
	#include "ManageScene.h"
#endif

#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

class CPlayer_Belonging;

class CMainGame
{
	DECLARE_SINGLETON(CMainGame);

private:
	CManageScene m_ManageScene;
	CPlayer_Belonging* m_Player[2];

public:
	HRESULT Initialize();
	void StartPhase();
	void KeyProcess();
	void Progress();
	void Render();
	void Release();

public:
	CPlayer_Belonging* getPlayerBelonging();

private:
	CMainGame();
public:
	~CMainGame();
};

