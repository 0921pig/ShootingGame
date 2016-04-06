#pragma once

#ifndef HEADER_ManageScene
	#define HEADER_ManageScene
	#include "ManageScene.h"
#endif

class CInfo_Player;

class CMainGame
{
	DECLARE_SINGLETON(CMainGame);

private:
	CManageScene m_ManageScene;
	CInfo_Player* m_Player[2];

public:
	HRESULT Initialize();
	void StartPhase();
	void KeyProcess();
	void Progress();
	void Render();
	void Release();

public:
	CInfo_Player* getPlayerInfo();

private:
	CMainGame();
public:
	~CMainGame();
};

