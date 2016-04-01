#pragma once

#ifndef HEADER_ManageScene
	#define HEADER_ManageScene
	#include "ManageScene.h"
#endif

class CMainGame
{
private:
	CManageScene m_ManageScene;

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

