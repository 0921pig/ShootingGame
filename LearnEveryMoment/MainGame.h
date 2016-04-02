#pragma once

#ifndef HEADER_ManageScene
	#define HEADER_ManageScene
	#include "ManageScene.h"
#endif

#ifndef HEADER_Lobby
	#define HEADER_Lobby
	#include "Lobby.h"
#endif


class CMainGame
{
private:
	//CManageScene m_ManageScene;
	CLobby m_Lobby;

public:
	HRESULT Initialize();
	void StartPhase();
	void KeyProcess();
	void Progress();
	void Render();
	void Release();

public:
	CMainGame();
	~CMainGame();
};

